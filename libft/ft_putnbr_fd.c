/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 12:28:44 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 07:13:35 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose:  write an integer to a file descriptor.
* Function implemented: ft_putnbr_fd
***	- n: integer to write.
***	- fd: file descriptor to write to.
***	- Handle negative numbers and writes digits recursively.
*/
/* ************************************************************************** */
void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	number;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	number = nb % 10 + '0';
	write(fd, &number, 1);
}
