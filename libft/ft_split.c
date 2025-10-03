/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:26:48 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 07:15:11 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose:  count the number of words in a string separated by a delimiter.
* Function implemented: count_words
***	- str: input string to scan.
***	- c: delimiter character.
***	- Return the number of words found.
*/
/* ************************************************************************** */
static int	count_words(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

/* ************************************************************************** */
/*
* Purpose:  free an array of strings up to a given index.
* Function implemented: free_tab
***	- tab: array of strings to free.
***	- n: number of strings to free.
*/
/* ************************************************************************** */
static void	free_tab(char **tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

/* ************************************************************************** */
/*
* Purpose:  fill the array of strings with words split by a delimiter.
* Function implemented: new_tab
***	- tab: array to fill with substrings.
***	- s: input string to split.
***	- c: delimiter character.
***	- Return 1 on success, 0 on failure (and frees allocated memory).
*/
/* ************************************************************************** */
static int	new_tab(char **tab, const char *s, char c)
{
	int	i;
	int	start;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			tab[word] = ft_substr(s, start, i - start);
			if (!tab[word])
				return (free_tab(tab, word), 0);
			word++;
		}
	}
	tab[word] = NULL;
	return (1);
}

/* ************************************************************************** */
/*
* Purpose:  split a string into an array of substrings separated by a delimiter.
* Function implemented: ft_split
***	- s: input string to split.
***	- c: delimiter character.
***	- Return a NULL-terminated array of substrings, or NULL on failure.
*/
/* ************************************************************************** */
char	**ft_split(const char *s, char c)
{
	char	**tab;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	tab = malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	if (!new_tab(tab, s, c))
		return (NULL);
	return (tab);
}
