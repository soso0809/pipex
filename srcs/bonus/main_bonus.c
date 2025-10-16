/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 15:35:12 by smetz             #+#    #+#             */
/*   Updated: 2025/10/16 08:21:46 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex_bonus	*data;

	data = init_pipex_bonus();
	if (!data)
		return (1);
	data->here_doc = 0;
	parse_input_bonus(data, argc, argv, envp);
	execute_commands_bonus(data, envp);
	free_pipex_bonus(data);
	get_next_line_free_all();
	return (0);
}
