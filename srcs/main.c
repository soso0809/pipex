/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:55:17 by smetz             #+#    #+#             */
/*   Updated: 2025/10/07 08:49:13 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	t_pipex *data;

	data = init_pipex();
	if (!data)
		return (1);
	/* This minimal main only parses input to allow building and basic tests */
	parse_input(data, argc, argv, envp);
	/* Print resolved paths for quick manual verification */
	if (data->cmd1_path)
		printf("cmd1_path: %s\n", data->cmd1_path);
	if (data->cmd2_path)
		printf("cmd2_path: %s\n", data->cmd2_path);
	/* cleanup and exit */
	return (0);
}
