/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:30:55 by mbastard          #+#    #+#             */
/*   Updated: 2021/12/09 19:30:58 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sort(va_list *arg, char type, int size)
{		
	if (type == 'c')
		size = ft_putchar(va_arg(*arg, int), size);
	else if (type == 's')
		size = ft_putstr(va_arg(*arg, char *), size);
	else if (type == 'p')
	{
		size = ft_putstr("0x", size);
		size = ft_puthexa(va_arg(*arg, uintptr_t), "0123456789abcdef", size);
	}
	else if (type == 'd' || type == 'i')
		size = ft_putnbr(va_arg(*arg, int), size);
	else if (type == 'u')
		size = ft_putunbr(va_arg(*arg, unsigned int), size);
	else if (type == 'x')
		size = ft_puthexa(va_arg(*arg, unsigned int), "0123456789abcdef", size);
	else if (type == 'X')
		size = ft_puthexa(va_arg(*arg, unsigned int), "0123456789ABCDEF", size);
	else if (type == '%')
		size = ft_putchar('%', size);
	return (size);
}

int	ft_printf(const char *format, ...)
{
	int				size;
	va_list			arg;

	size = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
			size = ft_sort(&arg, *++format, size);
		else
			size = ft_putchar(*format, size);
		format++;
	}
	va_end(arg);
	return (size);
}
