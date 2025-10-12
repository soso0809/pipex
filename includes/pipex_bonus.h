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

# include "pipex.h"

/* Here_doc configuration */
# define HERE_DOC_TEMP_FILE ".here_doc_tmp"
# define HERE_DOC_PERMS 0644

/* Bonus functions prototypes */
/* Parsing */
void	parse_input_bonus(t_pipex *pipex, int argc, char **argv, char **envp);
void	parse_commands_bonus(t_pipex *pipex, char **argv, char **envp);

/* Here_doc */
int		is_here_doc_mode(char **argv);
int		handle_here_doc(t_pipex *data);
char	*get_here_doc_input(char *limiter);
void	clean_here_doc(t_pipex *data);

/* Multiple pipes */
void	execute_commands(t_pipex *data, char **envp);

#endif
