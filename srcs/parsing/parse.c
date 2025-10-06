/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:56:50 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 13:56:51 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* ************************************************************************** */
/*
* Purpose:  allocate and initialize a t_pipex structure.
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

void	parse_input(t_pipex *pipex, int argc, char **argv, char **envp)
{
	if (argc != 5)
		ft_error("Usage: ./pipex infile cmd1 cmd2 outfile");
	pipex->fd_in = open(argv[1], O_RDONLY);
	if (pipex->fd_in < 0)
		ft_error("Error opening infile.");
	pipex->fd_out = open(argv[4], O_WRONLY);
	if (pipex->fd_out < 0)
		ft_error("Error opening outfile.");
	pipex->cmd1 = ft_split(argv[2]);
	pipex->cm2 = ft_split(argv[3]);
	if (!pipex->cmd1 || !pipex->cmd2)
		ft_error("Error splitting commands.");
	
}