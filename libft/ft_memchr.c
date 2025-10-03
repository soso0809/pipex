/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:15:58 by blackyuna         #+#    #+#             */
/*   Updated: 2025/10/03 07:08:29 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose:  locate the first occurrence of a byte in a memory area.
* Function implemented: ft_memchr
***	- s: pointer to the memory area to search.
***	- c: byte to search for (as int, interpreted as unsigned char).
***	- n: number of bytes to examine.
***	- Return a pointer to the matching byte or NULL if not found.
*/
/* ************************************************************************** */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)((unsigned char *)s + i));
		i++;
	}
	return (NULL);
}

/*int main(void)
{
	char str1[] = "Hello World";
	char *result1 = ft_memchr(str1, 'W', 11);
	printf("Test 1: %s\n", result1 ? result1 : "NULL");

	char str2[] = "Hello World";
	char *result2 = ft_memchr(str2, 'Z', 11);
	printf("Test 2: %s\n", result2 ? result2 : "NULL");

	int arr[] = {1, 2, 3, 4, 5};
	int *result3 = ft_memchr(arr, 3, 5 * sizeof(int));
	printf("Test 3: %d\n", result3 ? *result3 : -1);

	return (0);
}*/
