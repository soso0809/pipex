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

#include "pipex.h"
#include "pipex_bonus.h"

/* Macros locales pour here_doc */
#ifndef HERE_DOC_TEMP_FILE
# define HERE_DOC_TEMP_FILE ".here_doc_tmp"
#endif
#ifndef HERE_DOC_PERMS
# define HERE_DOC_PERMS 0644
#endif

/* ************************************************************************** */
/*
* Purpose: helper functions for parsing
* Function implemented:
***	- is_here_doc_mode: check if the program is running in here_doc mode.
***	- handle_here_doc: handle the here_doc functionality by reading input until
	limiter is found, writing it to a temporary file, and opening it for
	reading.
***	-*get_here_doc_input: read input from stdin until the limiter is
	encountered.
***	- clean_here_doc: remove the temporary file used for here-document
	functionality.
*/
/* ************************************************************************** */

/* ************************************************************************** */
/*
* Purpose: check if the program is running in here_doc mode.
* Function implemented: is_here_doc_mode
***	- argv: command-line arguments array.
* Return: 1 if "here_doc" mode is detected, 0 otherwise.
*/
/* ************************************************************************** */
int	is_here_doc_mode(char **argv)
{
	if (!argv || !argv[1])
		return (0);
	if (ft_strncmp(argv[1], "here_doc", 8) != 0)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*
* Purpose: handle the here_doc functionality by reading input until limiter is
	found, writing it to a temporary file, and opening it for reading.
* Function implemented: handle_here_doc
***	- data: pointer to t_pipex structure containing here_doc info.
* Behavior:
***	- Create a temporary file for here_doc input.
***	- Read user input until limiter is encountered.
***	- Write input to the temporary file.
***	- Open the temporary file for reading and sets data->fd_in.
***	- Handle errors by exiting with an error message.
*/
/* ************************************************************************** */
int	handle_here_doc(t_pipex_bonus *data)
{
	int		tmp;
	char	*content;

	if (!data)
		return (-1);
	tmp = open(HERE_DOC_TEMP_FILE, O_WRONLY | O_CREAT
			| O_TRUNC, HERE_DOC_PERMS);
	if (tmp == -1)
		return (-1);
	content = get_here_doc_input(data->limiter);
	if (content == NULL)
		return (-1);
	ft_putstr_fd(content, tmp);
	free(content);
	close(tmp);
	data->fd_in = open(HERE_DOC_TEMP_FILE, O_RDONLY);
	if (data->fd_in == -1)
		return (-1);
	return (0);
}

/* ************************************************************************** */
/*
* Purpose: read input from stdin until the limiter is encountered.
* Function implemented: get_here_doc_input
***	- limiter: string that marks the end of input.
* Behavior:
***	- Prompt user with "heredoc> ".
***	- Read lines from stdin.
***	- Stop reading when a line matches the limiter.
***	- Concatenate all lines (except the limiter) into a single string.
***	- Return the concatenated string.
*/
/* ************************************************************************** */

char	*get_here_doc_input(char *limiter)
{
	char	*line;
	char	*content;
	char	*tmp;

	content = ft_strdup("");
	if (!content)
		return (NULL);
	while (1)
	{
		ft_putstr_fd("here_doc> ", 1);
		line = get_next_line(0);
		if (!line || !ft_strncmp(line, limiter, ft_strlen(limiter)))
			break ;
		tmp = ft_strjoin(content, line);
		free(content);
		content = tmp;
		free(line);
	}
	if (line)
		free(line);
	return (content);
}

/* ************************************************************************** */
/*
* Purpose: remove the temporary file used for here-document functionality.
* Function implemented: clean_here_doc
***	- data: pointer to t_pipex structure containing here_doc info.
* Behavior:
***	- If data and data->here_doc are set, delete the temporary file.
*/
/* ************************************************************************** */
void	clean_here_doc(t_pipex_bonus *data)
{
	if (data && data->here_doc)
		unlink(HERE_DOC_TEMP_FILE);
}
