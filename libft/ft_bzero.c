/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 07:50:53 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 06:54:38 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose:  set the first n bytes of the memory area pointed to by s to zero.
* Function implemented: ft_bzero
***	- s: pointer to the memory area to zero.
***	- n: number of bytes to set to zero.
***	- Uses ft_memset to perform the operation.
*/
/* ************************************************************************** */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*int	main(void)
{
	char	buffer[10];
	int		i;

	i = 0;
	while (i < 10)
	{
		buffer[i] = 'A';
		i++;
	}
	// Display before ft_bzero
	printf("Before ft_bzero : ");

	i = 0;
	while (i < 10)
	{
		printf("%c ", buffer[i]);
		i++;
	}
	printf("\n");

	ft_bzero(buffer, 5);
	printf("After ft_bzero  : ");
	i = 0;
	while (i < 10)
	{
		if (buffer[i] == 0)
			printf("0 ");
		else
			printf("%c ", buffer[i]);
		i++;
	}
	printf("\n");

	return 0;
}*/
