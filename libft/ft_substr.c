/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:16:03 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 07:54:47 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose: extract a substring from a given string.
* Function implemented: ft_substr
***	- s: input string.
***	- start: starting index of the substring.
***	- len: maximum length of the substring.
***	- Return a newly allocated substring, or NULL on failure.
*/
/* ************************************************************************** */
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (s[i] && i < start)
		i++;
	j = 0;
	while (s[i] && j < len)
	{
		sub[j] = s[i];
		i++;
		j++;
	}
	sub[j] = '\0';
	return (sub);
}

/*int main()
{
	char	str[] = "Hello world";
	char	*str2 = ft_substr(str, 4, 8);
	char	*s = ft_substr("tripouille", 0, 42000);

	printf("Result : %s\n", s);
	printf("\n");
	free (s);
	return (0);

}*/
