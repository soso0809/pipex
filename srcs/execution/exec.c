/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:57:21 by smetz             #+#    #+#             */
/*   Updated: 2025/10/16 06:51:43 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

/* ************************************************************************** */
/*
* Purpose: main functions for executing
* Function implemented:
***	- execute_command: execute two commands connected by a pipe.
***	- child_process: execute a child process for one side of the pipe.
*/
/* ************************************************************************** */

static void	handle_redirections(t_pipex *data, int *pipe_fd, int is_cmd1)
{
	if (is_cmd1)
	{
		if (dup2(data->fd_in, STDIN_FILENO) == -1)
			ft_error("Failed to redirect input");
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			ft_error("Failed to redirect output to pipe.");
	}
	else
	{
		if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
			ft_error("Failed to redirect from pipe");
		if (dup2(data->fd_out, STDOUT_FILENO) == -1)
			ft_error("Failed to redirect output.");
	}
}

/* ************************************************************************** */
/*
 * Purpose: execute two commands connected by a pipe.
 * Function implemented: execute_commands
 * - data: pointer to pipex structure containing command info.
 * - envp: environment variables array.
 *** - Create a pipe.
 ***	- Fork twice to create two child processes.
 ***	- Each child runs child_process with appropriate arguments.
 ***	- Parent closes pipe fds and waits for both children.
 * Return: void.
 */
/* ************************************************************************** */
void	execute_commands(t_pipex *data, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(pipe_fd) == -1)
		ft_error("Pipe creation failed.");
	pid1 = fork();
	if (pid1 < 0)
		ft_error("Fork failed");
	if (pid1 == 0)
		child_process(data, envp, pipe_fd, 1);
	pid2 = fork();
	if (pid2 < 0)
		ft_error("Fork failed");
	if (pid2 == 0)
		child_process(data, envp, pipe_fd, 0);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	while (wait(NULL) > 0)
		;
}

/* ************************************************************************** */
/*
* Purpose: execute a child process for one side of the pipe.
* Function implemented: child_process
* - data: pointer to pipex structure containing command info.
* - envp: environment variables array.
* - pipe_fd: file descriptors for the pipe.
* - is_cmd1: flag to indicate which command to execute (1 for first, 0 for
	second).
***	- Redirect input/output as needed using dup2.
***	- Close unused pipe file descriptors.
***	- Execute the appropriate command with execve.
* Return: void (exits on error).
 */
/* ************************************************************************** */
void	child_process(t_pipex *data, char **envp, int *pipe_fd, int is_cmd1)
{
	if (!data || !envp || !pipe_fd)
		ft_error("Failed.");
	handle_redirections(data, pipe_fd, is_cmd1);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (is_cmd1)
		execve(data->cmd1_path, data->cmd1, envp);
	else
		execve(data->cmd2_path, data->cmd2, envp);
	if (is_cmd1)
		exit_error_cmd(data->cmd1[0], "Command execution failed.");
	else
		exit_error_cmd(data->cmd2[0], "Command execution failed.");
}
