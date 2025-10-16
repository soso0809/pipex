/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:35:12 by smetz             #+#    #+#             */
/*   Updated: 2025/10/16 10:14:25 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/* ************************************************************************** */
/*
* Purpose: helper functions for parsing
* Function implemented:
***	- *init_pipex_bonus: allocate and initialize a t_pipex_bonus structure.
***	- check_args_bonus: check validity of arguments and environment for bonus 
	pipex.
***	- parse_input_bonus: parse input arguments and environment for bonus pipex.
*/
/* ************************************************************************** */

/* ************************************************************************** */
/*
 * Purpose: allocate and initialize a t_pipex_bonus structure.
 * Function implemented: init_pipex_bonus
 *** - Allocate memory for t_pipex_bonus.
 *** - Initialise tous les membres à des valeurs par défaut.
 *** - Retourne un pointeur sur la structure initialisée.
 *** - En cas d'échec, appelle ft_error.
 */
/* ************************************************************************** */
t_pipex_bonus	*init_pipex_bonus(void)
{
	t_pipex_bonus	*pipex;

	pipex = malloc(sizeof(t_pipex_bonus));
	if (!pipex)
		ft_error("Error allocation pipex_bonus.");
	pipex->fd_in = -1;
	pipex->fd_out = -1;
	pipex->here_doc = 0;
	pipex->limiter = NULL;
	pipex->cmds = NULL;
	pipex->cmd_paths = NULL;
	return (pipex);
}

/* ************************************************************************** */
/*
 * Purpose: check validity of arguments and environment for bonus pipex.
 * Function implemented: check_args_bonus
 ***	- pipex: pointer to main pipex struct.
 ***	- argc: argument count.
 ***	- envp: environment variables.
 * Behavior:
 ***	- If argc < 5, free resources and print usage error.
 ***	- If envp is NULL, free resources and print environment error.
 ***	- If argc is not 5 or 6, free resources and print usage error.
 */
/* ************************************************************************** */
static void	check_args_bonus(t_pipex_bonus *pipex, int argc, char **argv,
		char **envp)
{
	if (argc < 5)
	{
		free_pipex_bonus(pipex);
		ft_error("Usage: ./pipex_bonus infile cmd1 cmd2 [cmd3 ...] outfile");
	}
	if (!envp)
	{
		free_pipex_bonus(pipex);
		ft_error("empty environment.");
	}
	if ((argc >= 5 && !ft_strncmp(argv[1], "here_doc", 8) && argc < 6)
		|| (argc < 5))
	{
		free_pipex_bonus(pipex);
		ft_error("Usage: ./pipex_bonus [here_doc LIMITER] cmd1 cmd2...outfile");
	}
}

/* ************************************************************************** */
/*
 * Purpose: parse input arguments and environment for bonus pipex.
 * Function implemented: parse_input_bonus
 ***	- pipex: pointer to main pipex struct.
 ***	- argc: argument count.
 ***	- argv: argument vector.
 ***	- envp: environment variables.
 * Behavior:
 ***	- Check validity of arguments and environment.
 ***	- Open input and output files as needed.
 ***	- Parse commands from arguments.
 */
/* ************************************************************************** */
void	parse_input_bonus(t_pipex_bonus *pipex, int argc, char **argv,
		char **envp)
{
	check_args_bonus(pipex, argc, argv, envp);
	open_files_bonus(pipex, argc, argv);
	parse_commands_bonus(pipex, argv, envp);
}
