/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:46:12 by smetz             #+#    #+#             */
/*   Updated: 2025/10/07 16:35:51 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* ************************************************************************** */
/*
* Purpose: helper functions for parsing
* Function implemented:
***	- free_str_array: helper for freeing string arrays
***	- open_files: handle opening files
***	- parse_commands: handle parsing and validating commands
*/
/* ************************************************************************** */

/* ************************************************************************** */
/*
* Purpose: free a NULL-terminated array of strings.
* Function implemented: free_str_array
***	- Iterate through the array and free each string.
***	- Free the array itself.
***	- Do nothing if the array is NULL.
*/
/* ************************************************************************** */
void	free_str_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}


/* ************************************************************************** */
/*
* Purpose: open input and output files for pipex.
* Function implemented: open_files
***	- Open input file for reading.
***	- On failure, free resources and exit with error.
***	- Open output file for writing (create/truncate).
***	- On failure, free resources and exit with error.
*/
/* ************************************************************************** */
void	open_files(t_pipex *pipex, char **argv)
{
	pipex->fd_in = open(argv[1], O_RDONLY);
	if (pipex->fd_in < 0)
	{
		free_pipex(pipex);
		ft_error("Error: cannot access input file.");
	}
	pipex->fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->fd_out < 0)
	{
		free_pipex(pipex);
		ft_error("Error: cannot access output file.");
	}
}

/* ************************************************************************** */
/*
* Purpose: parse and validate commands from argv.
* Function implemented: parse_commands
***	- Split argv[2] and argv[3] into argument arrays.
***	- Validate that commands exist and are non-empty.
***	- Get executable path for each command.
***	- On failure, free resources and exit with error.
*/
/* ************************************************************************** */
void	parse_commands(t_pipex *pipex, char **argv, char **envp)
{
	pipex->cmd1 = ft_split(argv[2], ' ');
	pipex->cmd2 = ft_split(argv[3], ' ');
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
