/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion_bis.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42luxembourg.lu>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:41:20 by smetz             #+#    #+#             */
/*   Updated: 2025/07/01 10:41:58 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_unsigned_int(va_list args)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	return (ft_putnbr_unsigned(nb));
}

int	handle_pointer(va_list args)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	return (ft_putptr(ptr));
}

int	handle_modulo(va_list args)
{
	(void)args;
	return (ft_putchar('%'));
}
