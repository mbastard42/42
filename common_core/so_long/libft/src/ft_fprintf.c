/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <mbastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 21:24:26 by mbastard          #+#    #+#             */
/*   Updated: 2022/04/11 16:01:48 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_fprintf(int fd, const char *format, ...)
{
	va_list			arg;

	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
			ft_sort(fd, *++format, &arg);
		else
			ft_putchar_fd(fd, *format);
		format++;
	}
	va_end(arg);
}

void	ft_sort(int fd, char id, va_list *arg)
{
	if (id == 'c')
		ft_putchar_fd(fd, va_arg(*arg, int));
	else if (id == 's')
		ft_putstr_fd(fd, va_arg(*arg, char *));
	else if (id == 'p')
	{
		ft_putstr_fd(fd, "0x");
		ft_putunbrbase_fd(fd, va_arg(*arg, uintptr_t), "0123456789abcdef");
	}
	else if (id == 'd' || id == 'i')
		ft_putnbr_fd(fd, va_arg(*arg, int));
	else if (id == 'u')
		ft_putunbr_fd(fd, va_arg(*arg, size_t));
	else if (id == 'x')
		ft_putunbrbase_fd(fd, va_arg(*arg, size_t), "0123456789abcdef");
	else if (id == 'X')
		ft_putunbrbase_fd(fd, va_arg(*arg, size_t), "0123456789ABCDEF");
	else if (id == '%')
		ft_putchar_fd(fd, '%');
}
