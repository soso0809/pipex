/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 09:21:27 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 07:58:47 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose: locate the last occurrence of a character in a string.
* Function implemented: ft_strrchr
***	- s: input string.
***	- c: character to search for.
***	- Return a pointer to the last occurrence of 'c' in 's', or NULL if not 
	found.
*/
/* ************************************************************************** */
char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*t;

	i = 0;
	t = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			t = (char *)&s[i];
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (t);
}

/*int	main(void)
{
	char	*str = "check string";
	char	*strft = "chek string";

	char	*t = strrchr(str, 'c');
	char	*tt = ft_strrchr(strft, 'c');
	printf("Original strrchr: %s\n", t);
	printf("My ft_strrchr: %s\n", tt);
	return (0);
}*/
