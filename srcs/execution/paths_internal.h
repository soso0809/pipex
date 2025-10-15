/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-15 08:01:14 by smetz             #+#    #+#             */
/*   Updated: 2025-10-15 08:01:14 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHS_INTERNAL_H
# define PATHS_INTERNAL_H

char	*get_path_value(char **envp);
char	**split_path_value(char **envp);
char	*direct_cmd_check(char *cmd);

#endif
