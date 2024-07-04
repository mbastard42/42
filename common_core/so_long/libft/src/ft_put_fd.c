/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <mbastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:38:26 by mbastard          #+#    #+#             */
/*   Updated: 2022/04/11 16:01:51 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(int fd, const char *str)
{
	int	i;

	i = -1;
	if (str)
		while (str[++i])
			ft_putchar_fd(fd, str[i]);
}

void	ft_putnbr_fd(int fd, int nbr)
{
	if (nbr == -2147483648)
		ft_putstr_fd(fd, "-2147483648");
	else
	{
		if (nbr < 0)
		{
			nbr *= -1;
			ft_putchar_fd(fd, '-');
		}
		if (nbr >= 10)
			ft_putnbr_fd(fd, nbr / 10);
		ft_putchar_fd(fd, "0123456789"[nbr % 10]);
	}
}

void	ft_putunbr_fd(int fd, size_t nbr)
{
	if (nbr >= 10)
		ft_putnbr_fd(fd, nbr / 10);
	ft_putchar_fd(fd, "0123456789"[nbr % 10]);
}

void	ft_putunbrbase_fd(int fd, size_t nbr, const char *base)
{
	size_t	len;

	len = ft_strlen(base, 0);
	if (nbr >= len)
		ft_putunbrbase_fd(fd, nbr / len, base);
	ft_putchar_fd(fd, base[nbr % len]);
}
