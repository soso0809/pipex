/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:40:24 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 07:57:12 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose:  copy n bytes from source to destination memory area, handling 
	overlap.
* Function implemented: ft_memmove
***	- dest: pointer to the destination memory area.
***	- src: pointer to the source memory area.
***	- len: number of bytes to copy.
***	- Return a pointer to dest. Handles overlapping memory areas safely.
*/
/* ************************************************************************** */
void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dest == src)
		return (dest);
	if (dest < src)
	{
		while (i < len)
		{
			((unsigned char *) dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else if (dest > src)
	{
		while (len > 0)
		{
			((unsigned char *) dest)[len - 1] = ((unsigned char *)src)[len -1];
			len--;
		}
	}
	return (dest);
}

/*int	main(void)
{
	// Test 1: Simple copy
	char str1[] = "Hello";
	char dest1[10] = {0};
	printf("Test 1 - Simple copy:\n");
	printf("Before: %s\n", dest1);
	ft_memmove(dest1, str1, 5);
	printf("After: %s\n\n", dest1);

	// Test 2: Overlap (move right)
	char str2[] = "Hello";
	printf("Test 2 - Overlap to the right:\n");
	printf("Before: %s\n", str2);
	ft_memmove(str2 + 1, str2, 4);
	printf("After: %s\n\n", str2);

	// Test 3: Overlap (move left)
	char str3[] = "Hello";
	printf("Test 3 - Overlap to the left:\n");
	printf("Before: %s\n", str3);
	ft_memmove(str3, str3 + 1, 4);
	printf("After: %s\n\n", str3);

	// Test 4: Copy single character
	char str4[] = "Hello";
	char dest4[2] = {0};
	printf("Test 4 - Copy single character:\n");
	printf("Before: %s\n", dest4);
	ft_memmove(dest4, str4, 1);
	printf("After: %s\n\n", dest4);

	// Test 5: Same pointer
	char str5[] = "Hello";
	printf("Test 5 - Same pointer:\n");
	printf("Before: %s\n", str5);
	ft_memmove(str5, str5, 5);
	printf("After: %s\n\n", str5);

	return (0);
}*/
