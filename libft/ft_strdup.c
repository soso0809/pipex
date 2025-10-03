/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 06:50:24 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 07:55:53 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose: duplicate a string (allocate and copy).
* Function implemented: ft_strdup
***	- s1: input string to duplicate.
***	- Return: pointer to the newly allocated duplicate string, or NULL on 
	failure.
*/
/* ************************************************************************** */
char	*ft_strdup(const char *s1)
{
	char	*s1dup;

	s1dup = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!s1dup)
		return (NULL);
	ft_strlcpy(s1dup, s1, ft_strlen(s1) + 1);
	return (s1dup);
}

/*int	main()
{
	char str[] = "Hello world";
	char *str2 = strdup(str);
	char *str3 = ft_strdup(str);

	printf("Original string: %s\n", str);
	printf("Duplicated string with original strdup: %s\n", str2);
	printf("Duplicated string with ft_strdup: %s\n", str3);

	// Test with NULL
	char *null_test = ft_strdup(NULL);
	printf("NULL test: %s\n", null_test ? "not NULL" : "NULL");

	// Free memory
	free(str2);
	free(str3);

}
*/
