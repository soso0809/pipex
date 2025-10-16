/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 00:00:00 by soso0809          #+#    #+#             */
/*   Updated: 2025/10/16 09:52:51 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/* ************************************************************************** */
/*
* Purpose: main functions for executing
* Function implemented:
***	- free_cmd_paths: free allocated command path strings and the array.
***	- free_cmds: free allocated command argument arrays and the outer array.
***	- free_pipex_bonus: free all allocated resources for the bonus pipex data 
	structure and close any open file descriptors owned by it.
*/
/* ************************************************************************** */

/* ************************************************************************** */
/*
* Purpose: free allocated command path strings and the array.
* Arguments:
* - data->cmd_paths: array of strings allocated for each command path.
* - data->cmd_count: number of entries in cmd_paths.
* Behavior:
***	- If cmd_paths is non-null, free each non-null string up to cmd_count,
	then free the array itself.
*/
/* ************************************************************************** */
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

/* ************************************************************************** */
/*
* Purpose: free allocated command argument arrays and the outer array.
* Arguments:
* - data->cmds: array of argv-style arrays (NULL-terminated) for each command.
* - data->cmd_count: number of commands (entries) in cmds.
* Behavior:
***	- If cmds is non-null, for each entry up to cmd_count free each non-null
	string in the inner NULL-terminated array, free the inner array, then
	free the outer array and nullify the pointer in data.
*/
/* ************************************************************************** */
static void	free_cmds(t_pipex_bonus *data)
{
	int	i;
	int	j;

	if (!data || !data->cmds)
		return ;
	i = 0;
	while (i < data->cmd_count)
	{
		j = 0;
		if (data->cmds[i])
		{
			while (data->cmds[i][j])
				free(data->cmds[i][j++]);
			free(data->cmds[i]);
			data->cmds[i] = NULL;
		}
		i++;
	}
	free(data->cmds);
	data->cmds = NULL;
}

/* ************************************************************************** */
/*
* Purpose: free all allocated resources for the bonus pipex data structure and
	close any open file descriptors owned by it.
* Arguments:
* - data: pointer to the t_pipex_bonus structure to free; if NULL the function
	returns immediately.
* Behavior:
***	- Free arrays of command paths and argument arrays via helper functions.
***	- Free limiter string if present.
***	- Close fd_in and fd_out if they are valid user-level fds (greater than 2).
***	- Free the data structure itself.
* Notes:
***	- The check for > 2 avoids closing standard fds (0,1,2). If your code may use
	negative or other sentinel values for closed fds, adapt these checks.
*/
/* ************************************************************************** */
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
