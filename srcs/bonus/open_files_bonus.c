/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:00:00 by smetz             #+#    #+#             */
/*   Updated: 2025/10/16 10:01:36 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/* ************************************************************************** */
/*
* Function implemented:
***	- open_files_here_doc: handle here_doc mode file opening.
***	- open_files_normal: handle normal mode file opening.
***	- open_files_bonus: open input and output files based on mode 
	(here_doc or normal).
*/
/* ************************************************************************** */

/* ************************************************************************** */
/*
* Purpose: handle here_doc mode file opening.
* Function implemented: open_files_here_doc
***	- pipex: pointer to the pipex_bonus struct.
***	- argc: argument count.
***	- argv: command-line arguments array.
* Behavior:
***	- Sets here_doc mode.
***	- Duplicates limiter string.
***	- Handles here_doc input.
***	- Opens output file in append mode.
*/
/* ************************************************************************** */
static void	open_files_here_doc(t_pipex_bonus *pipex, int argc, char **argv)
{
	pipex->here_doc = 1;
	pipex->limiter = ft_strdup(argv[2]);
	if (!pipex->limiter)
	{
		free_pipex_bonus(pipex);
		ft_error("Error allocation limiter.");
	}
	if (handle_here_doc(pipex) < 0)
	{
		free_pipex_bonus(pipex);
		ft_error("here_doc failed.");
	}
	pipex->fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
}

/* ************************************************************************** */
/*
* Purpose: handle normal mode file opening.
* Function implemented: open_files_normal
***	- pipex: pointer to the pipex_bonus struct.
***	- argc: argument count.
***	- argv: command-line arguments array.
* Behavior:
***	- Open input file for reading.
***	- Open output file for writing (truncates if exists, creates if not).
***	- Handle errors for file access.
*/
/* ************************************************************************** */
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

/* ************************************************************************** */
/*
* Purpose: open input and output files based on mode (here_doc or normal).
* Function implemented: open_files_bonus
***	- pipex: pointer to the pipex_bonus struct.
***	- argc: argument count.
***	- argv: command-line arguments array.
* Behavior:
***	- Checks if here_doc mode is requested.
***	- Calls appropriate file opening function.
***	- Handles errors for output file access.
*/
/* ************************************************************************** */
void	open_files_bonus(t_pipex_bonus *pipex, int argc, char **argv)
{
	if (!ft_strncmp(argv[1], "here_doc", 8))
		open_files_here_doc(pipex, argc, argv);
	else
		open_files_normal(pipex, argc, argv);
	if (pipex->fd_out < 0)
	{
		free_pipex_bonus(pipex);
		ft_error("cannot access output file.");
	}
}
