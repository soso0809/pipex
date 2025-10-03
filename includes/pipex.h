/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/10/03 18:24:36 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* --- Includes --- */
# include "libft.h"                  // Ta libft (libft/libft.h est dans -Ilibft)
# include <errno.h>                   // errno
# include <fcntl.h>                   // open
# include <stdio.h>                   // perror (pour les erreurs)
# include <stdlib.h>                  // malloc, free, exit
# include <string.h>                  // strerror
# include <sys/wait.h>                // wait, waitpid
# include <unistd.h>                  // read, write, close, pipe, fork, execve, dup2

/* --- Macros --- */
# define INFILE 0
# define OUTFILE 1
# define READ 0
# define WRITE 1
# define ERROR_MSG "Error\n"

/* --- Structures --- */
/* ************************************************************************** */
/*
* Purpose:  display a message to stderr and exit the program with a given
	status.
* Function implemented: ft_error
***	- File descriptor for input
***	- File descriptor for output
***	- Array of arguments for command 1
***	- Full path to command 1 (e.g.: "/bin/ls")
***	- Array of arguments for command 2
***	- Full path to command 2
***	- 1 if here_doc mode is enabled (bonus), 0 otherwise
***	- Delimiter for here_doc (e.g.: "EOF")
*/
/* ************************************************************************** */
	typedef struct s_data
{
	int		fd_in;
	int		fd_out;
	char	**cmd1;
	char	*cmd1_path;
	char	**cmd2;
	char	*cmd2_path;
	int		here_doc;
	char	*limiter;
}			t_data;

/* ************************************************************************** */
/* MANDATORY FUNCTION DECLARATIONS */
/* ************************************************************************** */

/* execution/exec.c */
void		execute_commands(t_data *data, char **envp);
void		setup_pipe(t_data *data);
void		child_process(t_data *data, char **envp, int *pipe_fd, int is_cmd1);
void		parent_process(t_data *data, int *pipe_fd);

/* parsing/parse.c */
t_data		*init_data(void);
void		parse_input(t_data *data, int argc, char **argv);
char		**split_cmd(char *cmd);
char		*get_cmd_path(char *cmd, char **envp);

/* utils/errors.c */
void		exit_error(char *msg);
void		exit_error_cmd(char *cmd, char *msg);

/* utils/ft_utils.c */
void		free_array(char **array);
char		*ft_strjoin_char(char *s1, char c);
