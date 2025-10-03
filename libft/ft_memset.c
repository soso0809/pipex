/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:21:35 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 07:10:02 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose:  fill a block of memory with a specific byte value.
* Function implemented: ft_memset
***	- b: pointer to the memory area to fill.
***	- c: byte value to set (as int, interpreted as unsigned char).
***	- len: number of bytes to set.
***	- Return a pointer to the memory area b.
*/
/* ************************************************************************** */
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

/*int	main(void)
{
	char	str[10] = "Hello";

	printf("Avant: %s\n", str);
	ft_memset(str, 'A', 4);
	printf("Apres: %s\n", str);

	return (0);
}*/
