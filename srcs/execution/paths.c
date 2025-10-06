/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:57:29 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 13:57:30 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* ************************************************************************** */
/*
* Functions implemented:
***	- free_array: free a dynamically allocated array of strings.
***	- *test_paths: test each directory in the PATH for the existence of the
	command.
***	- *get_cmd_path: find the full path of a command using the PATH environment
	variable.
/* ************************************************************************** */
/*
* Purpose:  free a dynamically allocated array of strings.
* Function implemented: free_array
***	- array: the array of strings to free.
*/
/* ************************************************************************** */
static void	free_array(char **array)
{
	int	i = 0;

	while (array && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/* ************************************************************************** */
/*
* Purpose: test each directory in the PATH for the existence of the command.
* Function implemented: test_paths
***	- paths: array of directory strings from PATH.
***	- cmd: command to search for.
* Return: full path to the command if found, otherwise NULL.
*/
/* ************************************************************************** */
static char	*test_paths(char **paths, char *cmd)
{
	int		j = 0;
	char	*tmp;
	char	*full_path;

	while (paths[j] != NULL)
	{
		tmp = ft_strjoin(paths[j], "/");
		full_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full_path, X_OK) == 0)
		{
			free_array(paths);
			return (full_path);
		}
		free(full_path);
		j++;
	}
	free_array(paths);
	return (NULL);
}

/* ************************************************************************** */
/*
* Purpose: find the full path of a command using the PATH environment variable.
* Function implemented: get_cmd_path
***	- cmd: the command to search for.
***	- envp: the environment variables array.
* Return: full path to the command if found, otherwise NULL.
*/
/* ************************************************************************** */
char	*get_cmd_path(char *cmd, char **envp)
{
	int		i;
	char	*paths_str;
	char	**paths;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			paths_str = envp[i] + 5;
			paths = ft_split(paths_str, ':');
			return (test_paths(paths, cmd));
		}
		i++;
	}
	return (NULL);
}
