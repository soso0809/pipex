/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42luxembourg.lu>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:28:09 by smetz             #+#    #+#             */
/*   Updated: 2025/07/01 10:42:10 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// functions to handle conversions
int	handle_char(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	return (ft_putchar(c));
}

int	handle_string(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		return (ft_putstr("(null)"));
	return (ft_putstr(str));
}

int	handle_int(va_list args)
{
	int	nb;

	nb = va_arg(args, int);
	return (ft_putnbr(nb));
}

int	handle_hexa_x(va_list args)
{
	unsigned int	hex;

	hex = va_arg(args, unsigned int);
	return (ft_puthexa(hex, 'x'));
}

int	handle_hexa_upx(va_list args)
{
	unsigned int	hex;

	hex = va_arg(args, unsigned int);
	return (ft_puthexa(hex, 'X'));
}
