/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auto-generated                                +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 07:30:00 by helper            #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"
#include "paths_internal.h"

/* ************************************************************************** */
/*
* Functions implemented:
***	- *get_path_value: retrieve the value of the PATH environment variable.
***	- **split_path_value: split the PATH environment variable into an array of 
	directories.
***	- *direct_cmd_check: check if the command is a direct path and executable.
*/
/* ************************************************************************** */

/* ************************************************************************** */
/*
 * Purpose: retrieve the value of the PATH environment variable.
 * Function implemented: get_path_value
 *** - envp: environment variables array.
 * Return: pointer to the PATH value string (skip "PATH=") or NULL if not found.
 */
/* ************************************************************************** */
char	*get_path_value(char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		return (NULL);
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

/* Split PATH value into array of directories, or NULL on error */

/* ************************************************************************** */
/*
 * Purpose: split the PATH environment variable into an array of directories.
 * Function implemented: split_path_value
 *** - envp: environment variables array.
 * Return: array of directory strings, or NULL on failure.
 */
/* ************************************************************************** */
char	**split_path_value(char **envp)
{
	char	*paths_str;
	char	**paths;

	paths_str = get_path_value(envp);
	if (!paths_str)
		return (NULL);
	paths = ft_split(paths_str, ':');
	return (paths);
}

/* If cmd contains '/',
	treat as path and return duplicated path if executable */

/* ************************************************************************** */
/*
 * Purpose: check if the command is a direct path and executable.
 * Function implemented: direct_cmd_check
 *** - cmd: command string (may contain '/').
 * Return: duplicated command string if executable, otherwise NULL.
 */
/* ************************************************************************** */
char	*direct_cmd_check(char *cmd)
{
	if (!cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	return (NULL);
}
