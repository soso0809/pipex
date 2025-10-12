/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 15:35:12 by smetz             #+#    #+#             */
/*   Updated: 2025/10/12 15:35:12 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*data;

	data = init_pipex();
	if (!data)
		return (1);
	parse_input_bonus(data, argc, argv, envp);
	execute_commands(data, envp);
	free_pipex(data);
	return (0);
}