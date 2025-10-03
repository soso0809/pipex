/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:35:18 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 07:54:20 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose: check if a character is present in a given set.
* Function implemented: is_in_set
***	- set: string containing the set of characters.
***	- c: character to check.
***	- Return 1 if 'c' is in 'set', 0 otherwise.
*/
/* ************************************************************************** */
static int	is_in_set(const char *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*
* Purpose: find the index of the first character in s1 not in set.
* Function implemented: get_firstchar
***	- s1: input string.
***	- set: string containing the set of characters to trim.
***	- Return the index of the first character not in set.
*/
/* ************************************************************************** */
static size_t	get_firstchar(const char *s1, const char *set)
{
	size_t	firstchar;

	firstchar = 0;
	while (s1[firstchar] && is_in_set(set, s1[firstchar]))
		firstchar++;
	return (firstchar);
}

/* ************************************************************************** */
/*
* Purpose: find the index after the last character in s1 not in set.
* Function implemented: get_lastchar
***	- s1: input string.
***	- set: string containing the set of characters to trim.
***	- Return the index after the last character not in set.
*/
/* ************************************************************************** */
static size_t	get_lastchar(const char *s1, const char *set)
{
	size_t	lastchar;

	lastchar = ft_strlen(s1);
	while (lastchar > 0 && is_in_set(set, s1[lastchar - 1]))
		lastchar--;
	return (lastchar);
}

/* ************************************************************************** */
/*
* Purpose: trim all characters in 'set' from the start and end of 's1'.
* Function implemented: ft_strtrim
***	- s1: input string to trim.
***	- set: string containing the set of characters to trim.
***	- Return a new string with characters in 'set' removed from both ends.
*/
/* ************************************************************************** */
char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	firstchar;
	size_t	lastchar;
	size_t	size;
	size_t	i;
	char	*result;

	if (!s1 || !set)
		return (ft_strdup(""));
	firstchar = get_firstchar(s1, set);
	lastchar = get_lastchar(s1, set);
	if (firstchar >= lastchar)
		return (ft_strdup(""));
	size = lastchar - firstchar;
	result = (char *)malloc(size + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < size)
	{
		result[i] = s1[firstchar + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*int	main()
{
	char *result= ft_strtrim("  Hello World  ", " ");
	printf("%s\n", result);
	return (0);
}*/
