/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 08:02:07 by smetz             #+#    #+#             */
/*   Updated: 2025/10/16 10:41:59 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/* ************************************************************************** */
/*
* Purpose: orchestrate execution of all pipeline commands (bonus).
* Behavior:
***	- Delegate the actual loop and per-command handling to loop_commands_bonus.
***	- Keep the function as a clear entry point for command execution.
*/
/* ************************************************************************** */
void	execute_commands_bonus(t_pipex_bonus *data, char **envp)
{
	loop_commands_bonus(data, envp);
}
