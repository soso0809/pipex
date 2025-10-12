/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:56:50 by smetz             #+#    #+#             */
/*   Updated: 2025/10/10 06:33:45 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


/* ************************************************************************** */
/*
* Purpose: main functions for parsing
* Function implemented:
***	- *init_pipex:allocate and initialize a t_pipex structure.
***	- free_pipex: free all resources allocated in t_pipex structure.
***	- parse_input: parse input arguments and initialize pipex structure.
*/
/* ************************************************************************** */

/* ************************************************************************** */
/*
* Purpose: allocate and initialize a t_pipex structure.
* Function implemented: init_pipex
***	- Allocate memory for t_pipex.
***	- Initialize all members to default values.
***	- Return a pointer to the initialized structure.
***	- On allocation failure, call ft_error with an error message.
*/
/* ************************************************************************** */
t_pipex	*init_pipex(void)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		ft_error("Error allocation pipex.");
	pipex->fd_in = -1;
	pipex->fd_out = -1;
	pipex->cmd1 = NULL;
	pipex->cmd1_path = NULL;
	pipex->cmd2 = NULL;
	pipex->cmd2_path = NULL;
	pipex->here_doc = 0;
	pipex->limiter = NULL;
	return (pipex);
}

/* ************************************************************************** */
/*
* Purpose: free all resources allocated in t_pipex structure.
* Function implemented: free_pipex
***	- Close file descriptors if open.
***	- Free command paths.
***	- Free command argument arrays.
***	- Free the t_pipex structure itself.
***	- Do nothing if pipex is NULL.
*/
/* ************************************************************************** */
void	free_pipex(t_pipex *pipex)
{
	if (!pipex)
		return ;
	if (pipex->fd_in > -1)
		close(pipex->fd_in);
	if (pipex->fd_out > -1)
		close(pipex->fd_out);
	if (pipex->cmd1_path)
		free(pipex->cmd1_path);
	if (pipex->cmd2_path)
		free(pipex->cmd2_path);
	free_str_array(pipex->cmd1);
	free_str_array(pipex->cmd2);
	free(pipex);
}

/* ************************************************************************** */
/*
* Purpose: parse input arguments and initialize pipex structure.
* Function implemented: parse_input
***	- Check argument count, exit with usage error if invalid.
***	- Check environment pointer, exit with error if NULL.
***	- Open input and output files.
***	- Parse and validate commands.
*/
/* ************************************************************************** */
void	parse_input(t_pipex *pipex, int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		free_pipex(pipex);
		ft_error("Usage: ./pipex infile cmd1 cmd2 outfile");
	}
	if (!envp)
	{
		free_pipex(pipex);
		ft_error("Error: empty environment.");
	}
	open_files(pipex, argv);
	parse_commands(pipex, argv, envp);
}
