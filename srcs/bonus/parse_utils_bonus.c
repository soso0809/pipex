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
void	parse_commands_bonus(t_pipex *pipex, char **argv, char **envp)
{
	int	cmd_pos;

	cmd_pos = pipex->here_doc ? 3 : 2;
	pipex->cmd1 = ft_split(argv[cmd_pos], ' ');
	pipex->cmd2 = ft_split(argv[cmd_pos + 1], ' ');
	if (!pipex->cmd1 || !pipex->cmd2 || !pipex->cmd1[0] || !pipex->cmd2[0])
	{
		free_pipex(pipex);
		ft_error("Error: invalid command.");
	}
	pipex->cmd1_path = get_cmd_path(pipex->cmd1[0], envp);
	pipex->cmd2_path = get_cmd_path(pipex->cmd2[0], envp);
	if (!pipex->cmd1_path || !pipex->cmd2_path)
	{
		free_pipex(pipex);
		ft_error("Error: command not found.");
	}
}
