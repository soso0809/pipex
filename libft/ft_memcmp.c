/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 10:52:00 by blackyuna         #+#    #+#             */
/*   Updated: 2025/10/03 07:57:06 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Purpose:  compare two memory areas byte by byte.
* Function implemented: ft_memcmp
***	- s1: pointer to the first memory area.
***	- s2: pointer to the second memory area.
***	- n: number of bytes to compare.
***	- Return 0 if the memory areas are equal, otherwise the difference between 
	the first differing bytes.
*/
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

/*int main(void)
{
    // Test 1: Compare two identical strings
    char str1[] = "Hello";
    char str2[] = "Hello";
    printf("Test 1 (same string): %d\n", ft_memcmp(str1, str2, 5));

    // Test 2: Compare two different strings
    char str3[] = "World";
    char str4[] = "Hello";
    printf("Test 2 (different strings): %d\n", ft_memcmp(str3, str4, 5));

    // Test 3: Compare with shorter length
    printf("Test 3 (length 3): %d\n", ft_memcmp(str3, str4, 3));

    // Test 4: Compare with numbers
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 6};
    printf("Test 4 (integer arrays): %d\n", ft_memcmp(arr1, arr2, sizeof(arr1)));

    return (0);
}*/
