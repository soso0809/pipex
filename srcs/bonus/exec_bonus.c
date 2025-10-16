/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 08:02:07 by smetz             #+#    #+#             */
/*   Updated: 2025/10/16 08:49:39 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/* ************************************************************************** */
/*
* Purpose: main functions for executing
* Function implemented:
***	- exec_one_bonus: fork and execute a single pipeline stage.
***	- exec_command_bonus: prepare and run a pipeline stage: create a pipe when 
	needed, fork/exec the command (exec_one_bonus), and update/close file 
	descriptors so the parent can continue building the pipeline.
***	- loop_commands_bonus: iterate over all commands and set up/execute each 
	pipeline stage.
*/
/* ************************************************************************** */

/* ************************************************************************** */
/*
* Purpose: fork and execute a single pipeline stage.
* args->fd_in : input file descriptor for this command (may be a file or the
	read end of the previous pipe).
* Function implemented: exec_one_bonus
* args->pipe_fd: pipe file descriptors to connect this command to the next
	(only valid when this is not the last command).
* Behavior:
***	- Fork a child
***	- In the child:
***	- Duplicate fd_in onto STDIN using dup_in_bonus()
***	- if not the last command:
***	- Duplicate pipe_fd[1] onto STDOUT using dup_out_bonus()
***	- Close both pipe ends (dup already duplicated the write end)
***	- Otherwise duplicate the final output file descriptor onto STDOUT
***	- Execute the command with exec_cmd_bonus()
***	- Parent returns immediately (caller manages closing/propagating fds)
*/
/* ************************************************************************** */

static void	exec_one_bonus(t_exec_args_bonus *args)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		ft_error("Fork failed");
	if (pid == 0)
	{
		dup_in_bonus(args->fd_in);
		if (args->idx < args->data->cmd_count - 1)
		{
			dup_out_bonus(args->pipe_fd[1]);
			close(args->pipe_fd[0]);
			close(args->pipe_fd[1]);
		}
		else
			dup_out_bonus(args->data->fd_out);
		exec_cmd_bonus(args->data->cmd_paths[args->idx],
			args->data->cmds[args->idx], args->envp);
	}
}

/* ************************************************************************** */
/*
* Purpose: prepare and run a pipeline stage: create a pipe when needed,
	fork/exec the command (exec_one_bonus), and update/close file descriptors
	so the parent can continue building the pipeline.
* Function implemented: exec_command_bonus
* Behavior:
* - If not the last command: create a pipe and store fds in args->pipe_fd
* - Call exec_one_bonus to fork and execute the command
* - Close the previous input fd if it is not the original input file
* - If not the last command: close the write end of the pipe in the parent and
	set args->fd_in to the pipe's read end for the next command
*/
/* ************************************************************************** */

static void	exec_command_bonus(t_exec_args_bonus *args)
{
	if (args->idx < args->data->cmd_count - 1)
	{
		if (pipe(args->pipe_fd) == -1)
			ft_error("Pipe creation failed.");
	}
	exec_one_bonus(args);
	if (args->fd_in != args->data->fd_in)
		close(args->fd_in);
	if (args->idx < args->data->cmd_count - 1)
	{
		close(args->pipe_fd[1]);
		args->fd_in = args->pipe_fd[0];
	}
}

/* ************************************************************************** */
/*
* Purpose: iterate over all commands and set up/execute each pipeline stage.
* Function implemented: loop_commands_bonus
* args:
* - data : pipeline data and file descriptors
* - envp : environment for exec
* Behavior:
***	- Start with the initial input fd (data->fd_in)
***	- For each command:
**	- Populate t_exec_args_bonus
***	- Call exec_command_bonus to create pipes, fork and exec the command
***	- Update fd_in with the read end of the last created pipe for the next
	iteration (exec_command_bonus manages closing of other fds)
*/
/* ************************************************************************** */

void	loop_commands_bonus(t_pipex_bonus *data, char **envp)
{
	int					pipe_fd[2];
	int					fd_in;
	int					i;
	t_exec_args_bonus	args;

	fd_in = data->fd_in;
	i = 0;
	while (i < data->cmd_count)
	{
		args.data = data;
		args.envp = envp;
		args.idx = i;
		args.fd_in = fd_in;
		args.pipe_fd = pipe_fd;
		exec_command_bonus(&args);
		fd_in = args.fd_in;
		i++;
	}
}
