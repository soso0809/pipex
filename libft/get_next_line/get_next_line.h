/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:40:33 by smetz             #+#    #+#             */
/*   Updated: 2025/10/10 18:43:49 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft.h"

/*
* Buffer size for reading from file descriptor
* Can be overridden at compile time with -D BUFFER_SIZE=n
*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

/*
* Maximum number of file descriptors that can be handled simultaneously
* Typically corresponds to the system limit
*/
# ifndef MAX_FD
#  define MAX_FD 1024
# endif

/*
* Main function to read a line from a file descriptor
* Returns the line read (including newline if present) or NULL on EOF/error
* Memory must be freed by the caller
*/
char	*get_next_line(int fd);

/*
* Free all internal static buffers used by get_next_line (all fds)
*/
void	get_next_line_free_all(void);

/*
* Helper functions for internal use
* read_and_accumulate: reads from fd and accumulates in buffer until newline/EOF
* extract_line_and_update_rest: extracts one line and updates static buffer
*/
char	*read_and_accumulate(int fd, char *rest);
char	*extract_line_and_update_rest(char **acc, char **rest);

#endif
