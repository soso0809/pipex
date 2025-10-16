/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 15:45:12 by smetz             #+#    #+#             */
/*   Updated: 2025/10/16 10:42:09 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/* ************************************************************************** */
/*
* Purpose: helper functions for parsing
* Function implemented:
***	- parse_commands_bonus: parse commands and initialize command arrays in
	t_pipex_bonus.
***	- free_cmds_paths: free allocated memory for command arrays and paths in
	t_pipex_bonus.
***	- parse_cmd_arrays: fill command and path arrays in t_pipex_bonus.
*/
/* ************************************************************************** */

static void	parse_cmd_arrays(t_pipex_bonus *pipex_bonus, char **argv,
				char **envp, int start);

/* ************************************************************************** */
/*
 * Purpose: parse commands and initialize command arrays in t_pipex_bonus.
 * Function implemented: parse_commands_bonus
 *** - Determine the starting index of commands in argv depending on here_doc.
 *** - Count the number of commands to execute.
 *** - Allocate the cmds and cmd_paths arrays in pipex_bonus.
 *** - Check validity of arguments and memory allocation.
 *** - Fill the arrays using parse_cmd_arrays.
 */
/* ************************************************************************** */
void	parse_commands_bonus(t_pipex_bonus *pipex_bonus, char **argv,
		char **envp)
{
	int	start;
	int	cmd_count;

	start = 2 + pipex_bonus->here_doc;
	cmd_count = 0;
	if (!argv[start])
		ft_error("Error: no commands provided.");
	while (argv[start + cmd_count + 1])
		cmd_count++;
	if (cmd_count <= 0)
		ft_error("Error: no command found.");
	pipex_bonus->cmd_count = cmd_count;
	pipex_bonus->cmds = ft_calloc(cmd_count, sizeof(char **));
	pipex_bonus->cmd_paths = ft_calloc(cmd_count, sizeof(char *));
	if (!pipex_bonus->cmds || !pipex_bonus->cmd_paths)
		ft_error("Error: malloc failed.");
	parse_cmd_arrays(pipex_bonus, argv, envp, start);
}

/* ************************************************************************** */
/*
 * Purpose: free allocated memory for command arrays and paths in t_pipex_bonus.
 * Function implemented: free_cmds_paths
 *** - Free each string in cmds and cmd_paths up to last.
 *** - Free the cmds and cmd_paths arrays.
 *** - Set pointers to NULL to avoid invalid access.
 */
/* ************************************************************************** */
static void	free_cmds_paths(t_pipex_bonus *pipex_bonus, int last)
{
	int	j;
	int	k;

	j = 0;
	while (j <= last)
	{
		if (pipex_bonus->cmds[j])
		{
			k = 0;
			while (pipex_bonus->cmds[j][k])
				free(pipex_bonus->cmds[j][k++]);
			free(pipex_bonus->cmds[j]);
		}
		if (pipex_bonus->cmd_paths[j])
			free(pipex_bonus->cmd_paths[j]);
		j++;
	}
	free(pipex_bonus->cmds);
	free(pipex_bonus->cmd_paths);
	pipex_bonus->cmds = NULL;
	pipex_bonus->cmd_paths = NULL;
}

/* ************************************************************************** */
/*
 * Purpose: fill command and path arrays in t_pipex_bonus.
 * Function implemented: parse_cmd_arrays
 *** - Split each command argument into tokens.
 *** - Validate command and allocate memory.
 *** - Find executable path for each command.
 *** - Free memory and exit on error.
 */
/* ************************************************************************** */
static void	parse_cmd_arrays(t_pipex_bonus *pipex_bonus, char **argv,
		char **envp, int start)
{
	int	idx;

	idx = 0;
	while (idx < pipex_bonus->cmd_count)
	{
		if (!argv[start + idx])
			ft_error("Error: missing command argument.");
		pipex_bonus->cmds[idx] = ft_split(argv[start + idx], ' ');
		if (!pipex_bonus->cmds[idx] || !pipex_bonus->cmds[idx][0])
		{
			free_cmds_paths(pipex_bonus, idx - 1);
			ft_error("Error: invalid command.");
		}
		pipex_bonus->cmd_paths[idx] = get_cmd_path(pipex_bonus->cmds[idx][0],
				envp);
		if (!pipex_bonus->cmd_paths[idx])
		{
			free_cmds_paths(pipex_bonus, idx);
			ft_error("Error: command not found.");
		}
		idx++;
	}
}
