/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/10/16 10:42:20 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "pipex.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

/* Here_doc configuration */
# define HERE_DOC_TEMP_FILE ".here_doc_tmp"
# define HERE_DOC_PERMS 0644

/* ************************************************************************** */
/*
 * Bonus structure for multi-pipes and here_doc
 ***	- fd_in, fd_out: input/output files
 ***	- here_doc: here_doc mode enabled
 ***	- limiter: here_doc delimiter
 ***	- cmd_count: number of commands
 ***	- cmds: array of commands
 ***	- cmd_paths: array of command paths
 */
/* ************************************************************************** */

typedef struct s_pipex_bonus
{
	int				fd_in;
	int				fd_out;
	int				here_doc;
	char			*limiter;
	int				cmd_count;
	char			***cmds;
	char			**cmd_paths;
}					t_pipex_bonus;

typedef struct s_exec_args_bonus
{
	t_pipex_bonus	*data;
	char			**envp;
	int				idx;
	int				fd_in;
	int				*pipe_fd;
}					t_exec_args_bonus;

/* exec_bonus.c*/
void				loop_commands_bonus(t_pipex_bonus *data, char **envp);

/* exec_utils_bonus.c */
void				close_and_update_fd_bonus(t_exec_args_bonus *args);
void				dup_in_bonus(int prev_fd);
void				dup_out_bonus(int fd_out);
void				exec_cmd_bonus(char *cmd_path, char **cmd, char **envp);

/* exec_commands_bonus.c */
void				execute_commands_bonus(t_pipex_bonus *data, char **envp);

/* free_bonus.c */
void				free_pipex_bonus(t_pipex_bonus *data);

/* here_doc.c*/
int					is_here_doc_mode(char **argv);
int					handle_here_doc(t_pipex_bonus *data);
char				*get_here_doc_input(char *limiter);
void				clean_here_doc(t_pipex_bonus *data);

/* open_files_bonus.c */
void				open_files_bonus(t_pipex_bonus *pipex, int argc,
						char **argv);

/* parse_bonus.c */
t_pipex_bonus		*init_pipex_bonus(void);
void				parse_input_bonus(t_pipex_bonus *pipex, int argc,
						char **argv, char **envp);

/* parse_utils_bonus.c */
void				parse_commands_bonus(t_pipex_bonus *pipex, char **argv,
						char **envp);

#endif
