/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/10/03 18:22:41 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "pipex.h" // Pour avoir accès à t_data et aux prototypes communs

/* --- Macros (Bonus) --- */
# define HERE_DOC_TEMP_FILE ".here_doc_tmp"
# define HERE_DOC_PERMS 0644 // Permissions pour le fichier temporaire

/* ************************************************************************** */
/* BONUS FUNCTION DECLARATIONS */
/* ************************************************************************** */

/* bonus/here_doc.c */
void	handle_here_doc(t_data *data);
int		is_here_doc_mode(char **argv);
void	clean_here_doc(t_data *data);
char	*get_here_doc_input(char *limiter);

/* bonus/multiple_pipes.c (si tu fais la partie multi-pipes) */
void	execute_multiple_pipes(t_data *data, char **envp, int cmd_count);

#endif
