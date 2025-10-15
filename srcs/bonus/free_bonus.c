/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soso0809 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 00:00:00 by soso0809          #+#    #+#             */
/*   Updated: 2025/10/15 00:00:00 by soso0809         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	free_cmd_paths(t_pipex_bonus *data)
{
	int	i;

	i = 0;
	if (data->cmd_paths)
	{
		while (i < data->cmd_count)
			free(data->cmd_paths[i++]);
		free(data->cmd_paths);
	}
}

static void	free_cmds(t_pipex_bonus *data)
{
	int	i;
	int	j;

	i = 0;
	if (data->cmds)
	{
		while (i < data->cmd_count)
		{
			j = 0;
			if (data->cmds[i])
			{
				while (data->cmds[i][j])
					free(data->cmds[i][j++]);
				free(data->cmds[i]);
			}
			i++;
		}
		free(data->cmds);
	}
}

void	free_pipex_bonus(t_pipex_bonus *data)
{
	if (!data)
		return ;
	free_cmd_paths(data);
	free_cmds(data);
	if (data->limiter)
		free(data->limiter);
	if (data->fd_in > 2)
		close(data->fd_in);
	if (data->fd_out > 2)
		close(data->fd_out);
	free(data);
}
