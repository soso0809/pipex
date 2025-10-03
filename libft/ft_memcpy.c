/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 08:05:49 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 07:09:04 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose:  copy n bytes from source memory area to destination memory area.
* Function implemented: ft_memcpy
***	- dest: pointer to the destination memory area.
***	- src: pointer to the source memory area.
***	- n: number of bytes to copy.
***	- Return a pointer to dest.
*/
/* ************************************************************************** */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == src)
		return (dest);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	// Test 1: Basic copy
	char src1[] = "Hello World";
	char dest1[20] = {0};
	int i;

	printf("Test 1 - Basic copy:\n");
	printf("Source: %s\n", src1);
	ft_memcpy(dest1, src1, 11);
	printf("Destination: %s\n\n", dest1);

	// Test 2: Copy only part of the string
	char src2[] = "Hello World";
	char dest2[20] = {0};
	printf("Test 2 - Partial copy:\n");
	printf("Source: %s\n", src2);
	ft_memcpy(dest2, src2, 5);
	printf("Destination: %s\n\n", dest2);

	// Test 3: Copy numbers
	int src3[] = {1, 2, 3, 4, 5};
	int dest3[5] = {0};
	printf("Test 3 - Copy numbers:\n");
	printf("Source array: ");
	i = 0;
	while (i < 5)
	{
		printf("%d ", src3[i]);
		i++;
	}
	printf("\n");
	ft_memcpy(dest3, src3, 5 * sizeof(int));
	printf("Destination array: ");
	i = 0;
	while (i < 5)
	{
		printf("%d ", dest3[i]);
		i++;
	}
	printf("\n\n");

	// Test 4: Same pointer
	char str4[] = "Hello";
	printf("Test 4 - Same pointer:\n");
	printf("Before: %s\n", str4);
	ft_memcpy(str4, str4, 5);
	printf("After: %s\n", str4);

	return (0);
}*/
