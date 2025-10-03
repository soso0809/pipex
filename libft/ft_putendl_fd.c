/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 12:20:21 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 07:57:34 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose:  write a string to a file descriptor, followed by a newline.
* Function implemented: ft_putendl_fd
***	- s: string to write.
***	- fd: file descriptor to write to.
***	- Write the string s to the file descriptor fd, followed by a newline.
*/
/* ************************************************************************** */
void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		i++;
	write(fd, s, i);
	write(fd, "\n", 1);
}
