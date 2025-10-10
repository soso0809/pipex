/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:18:33 by smetz             #+#    #+#             */
/*   Updated: 2025/10/10 18:38:29 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* ************************************************************************** */
/*
* Functions implemented in this file:
* - read_and_accumulate: reads from a file descriptor and accumulate data until
		a newline or EOF.
* - extract_line: extract a line from the accumulated buffer and update the
	rest pointer.
* - extract_line_and_update_rest: wrapper to extract a line and update the rest
	buffer.
*/
/* ************************************************************************** */

/* ************************************************************************** */
/*
* Purpose: read from the given file descriptor and accumulate data into a
	string
* until a newline character is found or EOF is reached.
* Function implemented: read_and_accumulate
***	- Read BUFFER_SIZE bytes at a time from fd
***	- Append read data to the accumulation string
***	- Stop reading when a newline is found or EOF/error occurs
*
* Parameters:
***	- int fd		: file descriptor to read from
***	- char *accum	: current accumulated string (may be empty)
*
* Return:
***	- Newly allocated string with accumulated data (including newline if found)
***	- NULL on error
*/
/* ************************************************************************** */
char	*read_and_accumulate(int fd, char *accum)
{
	ssize_t	bytes_read;
	char	*buffer;
	char	*tmp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(accum, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(accum), NULL);
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(accum, buffer);
		free(accum);
		accum = tmp;
	}
	free(buffer);
	return (accum);
}

/* ************************************************************************** */
/*
* Purpose: extract a line from the accumulated buffer and update the rest
	pointer.
* Function implemented: extract_line
***	- If a newline is found, extract up to and including the newline.
***	- Update *rest to point to the remaining string after the newline.
***	- If no newline, duplicate the whole buffer and sets *rest to NULL.
*
* Parameters:
***	- char **acc  : pointer to the accumulated buffer (will be freed)
***	- char **rest : pointer to the rest buffer (will be updated/freed)
***	- char *newline : pointer to the newline character in *acc (or NULL)
*
* Return:
***	- Newly allocated string containing the extracted line.
*/
/* ************************************************************************** */
static char	*extract_line(char **acc, char **rest, char *newline)
{
	char	*line;

	if (newline)
	{
		line = ft_substr(*acc, 0, newline - *acc + 1);
		if (*rest)
		{
			free(*rest);
			*rest = NULL;
		}
		*rest = ft_strdup(newline + 1);
	}
	else
	{
		line = ft_strdup(*acc);
		if (*rest)
		{
			free(*rest);
			*rest = NULL;
		}
		*rest = NULL;
	}
	free(*acc);
	*acc = NULL;
	return (line);
}

/* ************************************************************************** */
/*
* Purpose: wrapper to extract a line from the accumulated buffer and update
	rest.
* Function implemented: extract_line_and_update_rest
***	- Checks if the accumulated buffer is empty or NULL.
***	- Finds the first newline character in the buffer.
***	- Calls extract_line to extract the line and update rest.
*
* Parameters:
***	- char **acc  : pointer to the accumulated buffer (will be freed)
***	- char **rest : pointer to the rest buffer (will be updated/freed)
*
* Return:
***	- Newly allocated string containing the extracted line, or NULL if empty.
*/
/* ************************************************************************** */
char	*extract_line_and_update_rest(char **acc, char **rest)
{
	char	*newline;

	if (!*acc || **acc == '\0')
		return (NULL);
	newline = ft_strchr(*acc, '\n');
	return (extract_line(acc, rest, newline));
}
