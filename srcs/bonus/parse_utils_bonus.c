/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 15:45:12 by smetz             #+#    #+#             */
/*   Updated: 2025/10/12 15:45:12 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	parse_cmd_arrays(t_pipex_bonus *pipex_bonus, char **argv,
				char **envp, int start);

/* ************************************************************************** */
/*
* Purpose: Parse commands from argv and resolve their paths for bonus pipex.
* Function: parse_commands_bonus
***	- pipex: pointer to main pipex struct.
***	- argv: argument vector.
***	- envp: environment variables.
* Behavior:
***	- Determine command positions based on here_doc.
***	- Split command strings into argument arrays.
***	- Validate commands and resolve their executable paths.
***	- Handle errors and free resources if commands are invalid or not found.
*/
/* ************************************************************************** */
void	parse_commands_bonus(t_pipex_bonus *pipex_bonus, char **argv,
	char **envp)
{
	int	start;

	start = 2;
	if (pipex_bonus->here_doc)
		start = 3;
	pipex_bonus->cmd_count = 0;
	while (argv[start + pipex_bonus->cmd_count]
		&& argv[start + pipex_bonus->cmd_count + 1])
		pipex_bonus->cmd_count++;
	pipex_bonus->cmds = malloc(sizeof(char **) * pipex_bonus->cmd_count);
	pipex_bonus->cmd_paths = malloc(sizeof(char *) * pipex_bonus->cmd_count);
	if (!pipex_bonus->cmds || !pipex_bonus->cmd_paths)
		ft_error("Error: malloc failed.");
	parse_cmd_arrays(pipex_bonus, argv, envp, start);
}

static void	parse_cmd_arrays(t_pipex_bonus *pipex_bonus, char **argv,
	char **envp, int start)
{
	int	idx;

	idx = 0;
	while (idx < pipex_bonus->cmd_count)
	{
		pipex_bonus->cmds[idx] = ft_split(argv[start + idx], ' ');
		pipex_bonus->cmd_paths[idx] = get_cmd_path(pipex_bonus->cmds[idx][0],
				envp);
		if (!pipex_bonus->cmds[idx]
			|| !pipex_bonus->cmds[idx][0]
			|| !pipex_bonus->cmd_paths[idx])
		{
			free_pipex_bonus(pipex_bonus);
			ft_error("Error: invalid command.");
		}
		idx++;
	}
}
