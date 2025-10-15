/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-15 08:02:07 by smetz             #+#    #+#             */
/*   Updated: 2025-10-15 08:02:07 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// ...existing code...

static void	dup_and_exec_bonus(t_exec_args_bonus *args)
{
	dup_in_bonus(args->prev_fd);
	if (args->i < args->data->cmd_count - 1)
	{
		dup_out_bonus(args->pipe_fd[1]);
		close(args->pipe_fd[0]);
		close(args->pipe_fd[1]);
	}
	else
	{
		dup_out_bonus(args->data->fd_out);
	}
	exec_cmd_bonus(args->data->cmd_paths[args->i],
		args->data->cmds[args->i], args->envp);
}

static void	fork_and_run_bonus(t_exec_args_bonus *args)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		ft_error("Fork failed");
	if (pid == 0)
	{
		dup_and_exec_bonus(args);
	}
}

static void	loop_commands_bonus(t_pipex_bonus *data, char **envp)
{
	int					pipe_fd[2];
	int					prev_fd;
	int					i;
	t_exec_args_bonus	args;

	prev_fd = data->fd_in;
	i = 0;
	while (i < data->cmd_count)
	{
		if (i < data->cmd_count - 1)
		{
			if (pipe(pipe_fd) == -1)
				ft_error("Pipe creation failed.");
		}
		args.data = data;
		args.envp = envp;
		args.i = i;
		args.pipe_fd = pipe_fd;
		args.prev_fd = prev_fd;
		fork_and_run_bonus(&args);
		close_and_update_fd_bonus(&args);
		i++;
	}
}

void	execute_commands_bonus(t_pipex_bonus *data, char **envp)
{
	loop_commands_bonus(data, envp);
	while (wait(NULL) > 0)
		;
}
