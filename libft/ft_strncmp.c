/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:09:20 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 07:52:11 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose: compare two strings up to n characters.
* Function implemented: ft_strncmp
***	- s1: first input string.
***	- s2: second input string.
***	- n: maximum number of characters to compare.
***	- Return: difference between first differing characters, or 0 if equal.
*/
/* ************************************************************************** */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

/*int	main()
{
	char	*test1= "abcoe";
	char 	*test2 = "bcdoe";
	char	*ft_test1= "abcoe";
	char 	*ft_test2 = "bcdoe";
	int		t;
	int		ft_t;

	t = strncmp(test1, test2, 'o');
	ft_t = ft_strncmp(ft_test1, ft_test2, 'o');

	printf("Result of test is : %d\n", t);
	printf("Result of ft_test is : %d\n", ft_t);
}*/
