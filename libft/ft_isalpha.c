/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:50:20 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 06:56:08 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose:  check if a character is an alphabetic letter (A-Z or a-z).
* Function implemented: ft_isalpha
***	- character: the character to check (as int).
***	- Returns 1 if the character is a letter, 0 otherwise.
*/
/* ************************************************************************** */
int	ft_isalpha(int character)
{
	if ((character >= 'a' && character <= 'z')
		|| (character >= 'A' && character <= 'Z'))
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	char	*str;
	int		i;

	str[100] = "Hello123!";
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]))
			printf("'%c' est une lettre\n", str[i]);
		else
		{
			printf("'%c' n'est pas une lettre\n", str[i]);
			i++;
		}
	}
	return (0);
}*/
