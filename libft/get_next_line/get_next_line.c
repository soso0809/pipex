/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:59:37 by smetz             #+#    #+#             */
/*   Updated: 2025/10/10 18:38:27 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* File-scope static per-fd buffer so helper functions in this file can access
	it and we can provide a public function to free a specific slot. */
static char	*g_rest[MAX_FD];

/* ************************************************************************** */
/*
* Functions implemented in this file:
* - get_next_line: read the next line from a file descriptor, handling multiple
	fds.
* - get_next_line_bonus: wrapper for get_next_line to comply with bonus
	requirements.
* - free_and_null: rree and nullify given buffers.
* - clean_all_gnl_buffers: clean all static buffers used by get_next_line.
*/
/* ************************************************************************** */

/* ************************************************************************** */
/*
* Purpose: free the memory pointed to by acc and rest, and set their pointers to
		NULL.
* Function implemented: free_and_null
***	- Free *acc if not NULL and set it to NULL.
***	- Fres *rest if not NULL and set it to NULL.
e
* Parameters:
***	- char **acc  : pointer to the accumulated buffer
	(will be freed and set to NULL)
***	- char **rest : pointer to the rest buffer (will be freed and set to NULL)
*
* Return:
***	- Always returns 0.
*/
/* ************************************************************************** */
static int	free_and_null(char **acc, char **restp)
{
	if (*acc)
	{
		free(*acc);
		*acc = NULL;
	}
	if (*restp)
	{
		free(*restp);
		*restp = NULL;
	}
	return (0);
}

/* ************************************************************************** */
/*
* Purpose: read the next line from a file descriptor, handling multiple fds.
* Function implemented: get_next_line
***	- Use a static array to store leftover data for each fd (rest)
***	- Duplicate leftover data or initializes an empty string
***	- Read and accumulate data until a newline or EOF
***	- Extract the next line and update the rest buffer
*
* Parameters:
***	- int fd : file descriptor to read from
*
* Return:
***	- Newly allocated string containing the next line
	(including newline if present)
***	- NULL if no more lines or on error
*/
/* ************************************************************************** */
char	*get_next_line(int fd)
{
	char	*accumulation;
	char	*line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	if (g_rest[fd])
		accumulation = ft_strdup(g_rest[fd]);
	else
	{
		accumulation = malloc(1);
		if (!accumulation)
			return (NULL);
		accumulation[0] = '\0';
	}
	accumulation = read_and_accumulate(fd, accumulation);
	if (!accumulation || !*accumulation)
	{
		free_and_null(&accumulation, &g_rest[fd]);
		return (NULL);
	}
	line = extract_line_and_update_rest(&accumulation, &g_rest[fd]);
	return (line);
}

/* ************************************************************************** */
/*
* Free the internal static buffer used by get_next_line for a specific fd.
* Implemented at file scope so it can access the static `rest` array.
*/
/* ************************************************************************** */
void	get_next_line_free_fd(int fd)
{
	if (fd < 0 || fd >= MAX_FD)
		return ;
	if (g_rest[fd])
	{
		free(g_rest[fd]);
		g_rest[fd] = NULL;
	}
}

/* ************************************************************************** */
/*
* Free all internal static buffers used by get_next_line (all fds).
*/
/* ************************************************************************** */
void	get_next_line_free_all(void)
{
	int	i;

	i = 0;
	while (i < MAX_FD)
	{
		if (g_rest[i])
		{
			free(g_rest[i]);
			g_rest[i] = NULL;
		}
		i++;
	}
}

/* ************************************************************************** */
/*
* Purpose: bonus wrapper for get_next_line to comply with bonus requirements.
* Function implemented: get_next_line_bonus
***	- Simply call get_next_line with the given file descriptor.
*
* Parameters:
***	- int fd : file descriptor to read from
*
* Return:
***	- Newly allocated string containing the next line
	(including newline if present)
***	- NULL if no more lines or on error
*/
/* ************************************************************************** */
char	*get_next_line_bonus(int fd)
{
	return (get_next_line(fd));
}
