/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 20:01:30 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 07:58:10 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose: apply a function to each character of a string, passing its index.
* Function implemented: ft_striteri
***	- s: input string.
***	- f: function to apply to each character, with its index.
***	- Applie 'f' to each character of 's', passing the index and a pointer to 
	the character.
*/
/* ************************************************************************** */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
