/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 11:02:07 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 07:11:05 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose:  write a character to a given file descriptor.
* Function implemented: ft_putchar_fd
***	- c: the character to write.
***	- fd: the file descriptor on which to write.
*/
/* ************************************************************************** */
void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
