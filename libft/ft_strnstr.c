/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 21:25:25 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 07:57:52 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose: locate a substring in a string, where not more than 'len' characters 
	are searched.
* Function implemented: ft_strnstr
***	- haystack: the string to be searched.
***	- needle: the substring to search for.
***	- len: the maximum number of characters to search.
***	- Return a pointer to the first occurrence of needle in haystack, or NULL 
	if not found.
*/
/* ************************************************************************** */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!haystack && len == 0)
		return (NULL);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (needle[j] && ((i + j) < len) && (haystack[i + j] == needle[j]))
			j++;
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	*haystack;
	char	*needle;
	char	*result;

	// Test 1: normal test
	haystack = "Hello World";
	needle = "World";
	result = ft_strnstr(haystack, needle, 11);
	printf("Test 1: %s\n", result);

	// Test 2: empty needle
	haystack = "Hello World";
	needle = "";
	result = ft_strnstr(haystack, needle, 11);
	printf("Test 2: %s\n", result);

	// Test 3: needle longer than len
	haystack = "Hello World";
	needle = "World";
	result = ft_strnstr(haystack, needle, 5);
	printf("Test 3: %s\n", result);

	// Test 4: needle not founded
	haystack = "Hello World";
	needle = "Python";
	result = ft_strnstr(haystack, needle, 11);
	printf("Test 4: %s\n", result);

	return (0);
}*/
