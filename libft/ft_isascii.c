/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:15:01 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 06:56:40 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose:  check if a character is an ASCII character (0-127).
* Function implemented: ft_isascii
***	- character: the character to check (as int).
***	- Return 1 if the character is ASCII, 0 otherwise.
*/
/* ************************************************************************** */
int	ft_isascii(int character)
{
	if (character >= 0 && character <= 127)
		return (1);
	return (0);
}
