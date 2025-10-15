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
