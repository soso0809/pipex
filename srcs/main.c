/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:55:17 by smetz             #+#    #+#             */
/*   Updated: 2025/10/10 11:13:18 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex *data;

	data = init_pipex();
	if (!data)
		return (1);
	parse_input(data, argc, argv, envp);
	execute_commands(data, envp);
	free_pipex(data);
	return (0);
}
