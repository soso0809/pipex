/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42luxembourg.lu>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:23:41 by smetz             #+#    #+#             */
/*   Updated: 2025/07/01 11:10:14 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const t_conversion	g_conversions[] = {
{'c', handle_char}, {'s', handle_string}, {'d', handle_int}, {'i',
	handle_int}, {'x', handle_hexa_x}, {'X', handle_hexa_upx}, {'u',
	handle_unsigned_int}, {'%', handle_modulo}, {'p', handle_pointer},
{'\0', NULL} // Fin du tableau
};

int	parse_format(const char *format, va_list args,
		const t_conversion *conversions)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			j = -1;
			while (conversions[++j].conv)
			{
				if (conversions[j].conv == format[i])
				{
					count += conversions[j].func(args);
					break ;
				}
			}
		}
		else
			count += ft_putchar(format[i]);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	if (!format)
		return (0);
	va_start(args, format);
	count = parse_format(format, args, g_conversions);
	va_end(args);
	return (count);
}
