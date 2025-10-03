/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 14:14:57 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 07:51:37 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose: apply a function to each character of a string, creating a new string.
* Function implemented: ft_strmapi
***	- s: input string.
***	- f: function to apply to each character (with its index).
***	- Return a new string with the results of 'f', or NULL on error.
*/
/* ************************************************************************** */
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*result;

	i = 0;
	if (!s || !f)
		return (NULL);
	result = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*
// Fonction passée à ft_strmapi : majuscule si index pair (if index is even)
char	to_upper_even(unsigned int i, char c)
{
	if (i % 2 == 0 && c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	main(void)
{
	const char	*str = "hello42";
	char		*result;

	result = ft_strmapi(str, to_upper_even);
	if (result == NULL)
	{
		printf("Error: allocation or pointer is NULL\n");
		return (1);
	}
	printf("Original  : %s\n", str);
	printf("Transformé: %s\n", result);

	free(result);
	return (0);
}*/
