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
#include "get_next_line/get_next_line.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex_bonus	*data;

	data = malloc(sizeof(t_pipex_bonus));
	if (!data)
		return (1);
	parse_input_bonus(data, argc, argv, envp);
	execute_commands_bonus(data, envp);
	free(data);
	get_next_line_free_all();
	return (0);
}
