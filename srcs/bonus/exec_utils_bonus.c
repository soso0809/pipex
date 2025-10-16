/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 07:50:01 by smetz             #+#    #+#             */
/*   Updated: 2025/10/16 09:44:36 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/* ************************************************************************** */
/*
* Purpose: main functions for executing
* Function implemented:
***	- close_and_update_fd_bonus: close unneeded file descriptors and prepare 
	args->fd_in for the next pipeline stage.
***	- dup_in_bonus: duplicate prev_fd onto STDIN for the child process.
***	- dup_out_bonus:
***	- exec_cmd_bonus:
*/
/* ************************************************************************** */

/* ************************************************************************** */
/*
* Purpose: close unneeded file descriptors and prepare args->fd_in for the next
	pipeline stage.
* Arguments:
* - args->fd_in: current input fd for this command (may be original infile or
	the read end of the previous pipe).
* - args->pipe_fd: pipe fds connecting this command to the next.
* - args->idx: index of the current command (0-based).
* - args->data->fd_in: original input file descriptor (should not be closed here).
* - args->data->cmd_count: total number of commands in the pipeline.
* Behavior:
***	- Close args->fd_in if it is not the original infile fd.
***	- If this is not the last command, close the write end of the pipe and set
	args->fd_in to the read end so the parent can use it for the next command.
***	- If this is the last command, close the read end of the pipe (no next cmd).
*/
/* ************************************************************************** */
void	close_and_update_fd_bonus(t_exec_args_bonus *args)
{
	if (args->fd_in != args->data->fd_in)
		close(args->fd_in);
	if (args->idx < args->data->cmd_count - 1)
	{
		close(args->pipe_fd[1]);
		args->fd_in = args->pipe_fd[0];
	}
	else
	{
		close(args->pipe_fd[0]);
	}
}

/* ************************************************************************** */
/*
* Purpose: duplicate prev_fd onto STDIN for the child process.
* Arguments:
* - prev_fd: file descriptor to be duplicated to STDIN (0)
* Behavior:
***	- Use dup2(prev_fd, 0) and calls ft_error on failure.
*/
/* ************************************************************************** */
void	dup_in_bonus(int prev_fd)
{
	if (dup2(prev_fd, 0) == -1)
		ft_error("dup2 in");
}

/* ************************************************************************** */
/*
* Purpose: duplicate fd_out onto STDOUT for the child process.
* Arguments:
* - fd_out: file descriptor to be duplicated to STDOUT (1)
* Behavior:
***	- Use dup2(fd_out, 1) and call ft_error on failure.
*/
/* ************************************************************************** */
void	dup_out_bonus(int fd_out)
{
	if (dup2(fd_out, 1) == -1)
		ft_error("dup2 out");
}

/* ************************************************************************** */
/*
* Purpose: execute a command in the child process using execve.
* Arguments:
* - cmd_path: path to the executable
* - cmd: argv array (NULL-terminated)
* - envp: environment variables array
* Behavior:
***	- Calls execve; on failure, prints an error and exits via exit_error_cmd.
*/
/* ************************************************************************** */
void	exec_cmd_bonus(char *cmd_path, char **cmd, char **envp)
{
	if (execve(cmd_path, cmd, envp) == -1)
		exit_error_cmd(cmd[0], "Command execution failed.");
}
