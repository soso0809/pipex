/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-15 07:50:01 by smetz             #+#    #+#             */
/*   Updated: 2025-10-15 07:50:01 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_and_update_fd_bonus(t_exec_args_bonus *args)
{
	if (args->prev_fd != args->data->fd_in)
		close(args->prev_fd);
	if (args->i < args->data->cmd_count - 1)
	{
		close(args->pipe_fd[1]);
		args->prev_fd = args->pipe_fd[0];
	}
}

void	dup_in_bonus(int prev_fd)
{
	if (dup2(prev_fd, 0) == -1)
		ft_error("dup2 in");
}

void	dup_out_bonus(int fd_out)
{
	if (dup2(fd_out, 1) == -1)
		ft_error("dup2 out");
}

void	exec_cmd_bonus(char *cmd_path, char **cmd, char **envp)
{
	execve(cmd_path, cmd, envp);
	ft_error("Command execution failed.");
}
