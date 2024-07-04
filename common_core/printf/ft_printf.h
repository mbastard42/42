/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:31:19 by mbastard          #+#    #+#             */
/*   Updated: 2021/12/09 19:31:21 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);

int	ft_putchar(char c, int size);
int	ft_putstr(char *s, int size);
int	ft_putnbr(int n, int size);
int	ft_putunbr(unsigned int n, int size);
int	ft_puthexa(unsigned long n, char *base, int size);

#endif
