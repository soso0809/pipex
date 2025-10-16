/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:57:29 by smetz             #+#    #+#             */
/*   Updated: 2025/10/16 08:31:12 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paths_internal.h"
#include "pipex.h"

/* ************************************************************************** */
/*
* Functions implemented:
***	- free_array: free a dynamically allocated array of strings.
***	- *make_full_path: join a directory and command to form a full path.
***	- *test_paths: test each directory in the PATH for the existence of the
	command.
*** - *get_cmd_path: find the full path of a command using the PATH environment
	variable.
*/
/* ************************************************************************** */

/* ************************************************************************** */
/*
 * Purpose:  free a dynamically allocated array of strings.
 * Function implemented: free_array
 ***	- array: the array of strings to free.
 */
/* ************************************************************************** */
static void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/* ************************************************************************** */
/*
 * Purpose: join a directory and command to form a full path.
 * Function implemented: make_full_path
 ***	- dir: directory string.
 ***	- cmd: command string.
 * Return: newly allocated string with full path, or NULL on failure.
 */
/* ************************************************************************** */
static char	*make_full_path(const char *dir, const char *cmd)
{
	char	*tmp;
	char	*full;

	if (!dir || !cmd)
		return (NULL);
	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	full = ft_strjoin(tmp, cmd);
	free(tmp);
	return (full);
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
	int		j;
	char	*full_path;

	j = 0;
	if (!paths)
		return (NULL);
	while (paths[j] != NULL)
	{
		full_path = make_full_path(paths[j], cmd);
		if (!full_path)
		{
			free_array(paths);
			return (NULL);
		}
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
	char	**paths;
	char	*full_path;

	full_path = NULL;
	if (!cmd || !envp)
		return (NULL);
	paths = split_path_value(envp);
	if (!paths)
		return (NULL);
	full_path = test_paths(paths, cmd);
	return (full_path);
}
