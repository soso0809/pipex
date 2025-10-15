/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:35:12 by smetz             #+#    #+#             */
/*   Updated: 2025/10/12 14:35:12 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/* ************************************************************************** */
/*
* Purpose: helper functions for parsing
* Function implemented:
***	- check_args_bonus: check validity of arguments and environment for bonus
	pipex.
***	- open_files_bonus: open input and output files for bonus pipex.
***	- parse_input_bonus: parse input arguments and environment for bonus pipex.
*/
/* ************************************************************************** */

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
* Purpose: open input and output files for bonus pipex.
* Function implemented: open_files_bonus
***	- pipex: pointer to main pipex struct.
***	- argc: argument count.
***	- argv: argument vector.
* Behavior:
***	- If here_doc mode, set limiter and open output file in append mode.
***	- Otherwise, open input file for reading and output file for writing
	(truncate).
***	- On failure to open files, free resources and print error.
*/
/* ************************************************************************** */
static void	open_files_here_doc(t_pipex_bonus *pipex, int argc, char **argv)
{
	pipex->here_doc = 1;
	pipex->limiter = argv[2];
	if (handle_here_doc(pipex) < 0)
	{
		free_pipex_bonus(pipex);
		ft_error("here_doc failed.");
	}
	pipex->fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
}

static void	open_files_normal(t_pipex_bonus *pipex, int argc, char **argv)
{
	pipex->fd_in = open(argv[1], O_RDONLY);
	if (pipex->fd_in < 0)
	{
		free_pipex_bonus(pipex);
		ft_error("cannot access input file.");
	}
	pipex->fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
}

static void	open_files_bonus(t_pipex_bonus *pipex, int argc, char **argv)
{
	if (argc == 6 && !ft_strncmp(argv[1], "here_doc", 8))
		open_files_here_doc(pipex, argc, argv);
	else
		open_files_normal(pipex, argc, argv);
	if (pipex->fd_out < 0)
	{
		free_pipex_bonus(pipex);
		ft_error("cannot access output file.");
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
