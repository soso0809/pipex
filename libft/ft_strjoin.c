/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:12:45 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 07:49:42 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose: concatenate two strings into a new string.
* Function implemented: ft_strjoin
***	- s1: first input string.
***	- s2: second input string.
***	- Return a newly allocated string containing s1 followed by s2.
***	- Return NULL if allocation fails or if s1 or s2 is NULL.
*/
/* ************************************************************************** */
char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*newstr;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	newstr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (s1[i])
		newstr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		newstr[j++] = s2[i++];
	newstr[j] = '\0';
	return (newstr);
}

/*int	main()
{
	char	s1[]= "Hello";
	char	s2[]= "world";
	char	*strcat = ft_strjoin(s1, s2);
	printf("The result is: %s\n", strcat);
	free(strcat);
	return (0);
}*/
