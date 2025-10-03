/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:09:00 by smetz             #+#    #+#             */
/*   Updated: 2025/10/03 07:00:13 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*
* Purpose:  calculate the length of an integer when converted to a string.
* Function implemented: int_length (static helper for ft_itoa)
***	- n: the integer to measure.
***	- Return the number of characters needed (including sign if negative).
*/
/* ************************************************************************** */
static int	int_length(int n)
{
	int		length;
	long	nb;

	nb = n;
	length = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		length ++;
		nb = -nb;
	}
	while (nb > 0)
	{
		length++;
		nb = nb / 10;
	}
	return (length);
}

/* ************************************************************************** */
/*
* Purpose: convert an integer to its string representation.
* Function implemented: ft_itoa
***	- n: the integer to convert.
***	- Return a pointer to a newly allocated string representing the integer.
***	- Handle negative numbers and zero.
*/
/* ************************************************************************** */
char	*ft_itoa(int n)
{
	size_t	i;
	size_t	len;
	long	nb;
	char	*str;

	i = 0;
	nb = n;
	len = int_length(n);
	str = (char *)malloc(sizeof(char ) * (len + 1));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
		i = 1;
	}
	str[len] = '\0';
	while (len > i)
	{
		str[len - 1] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	return (str);
}
/*int	main()
{
	char	*s1 = ft_itoa(42);
	printf("The string s1 is: %s\n", s1);
	free(s1);
	char	*s2 = ft_itoa(-123);
	printf("The string s2 is: %s\n", s2);
	free(s2);
	char	*s3 = ft_itoa(0);
	printf("The string s3 is: %s\n", s3);
	free(s3);
	return(0);
}*/
