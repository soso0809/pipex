/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:52:23 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 06:55:30 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose:  check if a character is alphanumeric (letter or digit).
* Function implemented: ft_isalnum
***	- character: the character to check.
***	- Return 1 if the character is a letter (A-Z, a-z) or a digit (0-9).
***	- Return 0 otherwise.
*/
/* ************************************************************************** */
int	ft_isalnum(int character)
{
	if ((character >= '0' && character <= '9')
		|| (character >= 'A' && character <= 'Z')
		|| (character >= 'a' && character <= 'z'))
		return (1);
	return (0);
}
