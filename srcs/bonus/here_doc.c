/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:57:57 by smetz             #+#    #+#             */
/*   Updated: 2025/10/10 18:02:29 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	is_here_doc_mode(char **argv)
{
	if (!argv || !argv[1])
		return (0);
	if (ft_strncmp(argv[1], "here_doc", 9) != 0)
		return (0);
	return (1);
}

void	handle_here_doc(t_pipex *data)
{
	int		tmp;
	char	*content;
	
	if (!data)
		return ;
	tmp = open(HERE_DOC_TEMP_FILE, O_WRONLY | O_CREAT | O_TRUNC, HERE_DOC_PERMS);
	if (tmp == -1)
		exit_error("Could not create temporary file for here_doc.");
	content = get_here_doc_input(data->limiter);
	if (content == NULL)
		exit_error("Could not access to here_doc.");
	ft_putstr_fd(content, tmp);
	free(content);
	close(tmp);
	data->fd_in = open(HERE_DOC_TEMP_FILE, O_RDONLY);
	if (data->fd_in == -1)
		exit_error("Could not open here_doc temporary file for reading");
}

char	*get_here_doc_input(char *limiter)
{
	char	*line;
	char	*content;
	char	*tmp;

	content = ft_strdup("");
	if (!content)
		return (NULL);
}

void	clean_here_doc(t_pipex *data);
