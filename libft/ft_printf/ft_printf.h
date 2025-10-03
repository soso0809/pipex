/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42luxembourg.lu>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:41:17 by smetz             #+#    #+#             */
/*   Updated: 2025/07/01 10:53:24 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_puthexa(unsigned long n, const char format);
int	ft_putptr(void *ptr);

//structures to handle conversion with each char after %
typedef struct s_conversion
{
	char	conv;
	int		(*func)(va_list args);
}	t_conversion;

int	handle_char(va_list args);
int	handle_string(va_list args);
int	handle_int(va_list args);
int	handle_unsigned_int(va_list args);
int	handle_pointer(va_list args);
int	handle_modulo(va_list args);
int	handle_hexa_x(va_list args);
int	handle_hexa_upx(va_list args);

#endif
