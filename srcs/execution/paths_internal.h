/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auto-generated                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 07:30:00 by helper            #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHS_INTERNAL_H
# define PATHS_INTERNAL_H

char	*get_path_value(char **envp);
char	**split_path_value(char **envp);
char	*direct_cmd_check(char *cmd);

#endif
