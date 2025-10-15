/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 08:02:07 by smetz             #+#    #+#             */
/*   Updated: 2025/10/15 08:02:07 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execute_commands_bonus(t_pipex_bonus *data, char **envp)
{
	loop_commands_bonus(data, envp);
}
