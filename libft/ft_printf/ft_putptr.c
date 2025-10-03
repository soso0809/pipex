/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42luxembourg.lu>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 06:56:48 by smetz             #+#    #+#             */
/*   Updated: 2025/07/01 10:55:33 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int				count;
	unsigned long	adress;

	if (ptr == 0)
		return (write(1, "(nil)", 5));
	adress = (unsigned long)ptr;
	count = 0;
	count += ft_putstr("0x");
	count += ft_puthexa(adress, 'x');
	return (count);
}
