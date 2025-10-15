/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/10/10 13:37:49 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include "pipex.h"


/*
* Structure bonus multi-pipes et here_doc
***	- fd_in, fd_out : fichiers d'entrée/sortie
***	- here_doc : mode here_doc activé
***	- limiter : délimiteur here_doc
***	- cmd_count : nombre de commandes
***	- cmds : tableau de commandes
***	- cmd_paths : tableau des chemins des commandes
*/
typedef struct s_pipex_bonus
{
	int		fd_in;
	int		fd_out;
	int		here_doc;
	char	*limiter;
	int		cmd_count;
	char	***cmds;
	char	**cmd_paths;
} t_pipex_bonus;

typedef struct s_exec_args_bonus {
	t_pipex_bonus *data;
	char **envp;
	int i;
	int *pipe_fd;
	int prev_fd;
} t_exec_args_bonus;

void	dup_in_bonus(int prev_fd);
void	dup_out_bonus(int fd_out);
void	exec_cmd_bonus(char *cmd_path, char **cmd, char **envp);
void	close_and_update_fd_bonus(t_exec_args_bonus *args);

/* Here_doc configuration */
# define HERE_DOC_TEMP_FILE ".here_doc_tmp"
# define HERE_DOC_PERMS 0644

/* Bonus functions prototypes */
void	parse_input_bonus(t_pipex_bonus *pipex, int argc,
			char **argv, char **envp);
void	parse_commands_bonus(t_pipex_bonus *pipex,
			char **argv, char **envp);
int		is_here_doc_mode(char **argv);
int		handle_here_doc(t_pipex_bonus *data);
char	*get_here_doc_input(char *limiter);
void	clean_here_doc(t_pipex_bonus *data);
void	execute_commands_bonus(t_pipex_bonus *data, char **envp);
void	free_pipex_bonus(t_pipex_bonus *data);

#endif