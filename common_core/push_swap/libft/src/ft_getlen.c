/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <mbastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:29:31 by mbastard          #+#    #+#             */
/*   Updated: 2022/03/21 21:03:21 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlen(const char *str, char c)
{
	size_t	len;

	len = 0;
	if (str)
	{
		while (str[len] != c && str[len])
			len++;
		if (!str[len] && c)
			return (0);
	}
	return (len);
}

size_t	ft_tablen(char **tab, const char *str)
{
	size_t	len;

	len = 0;
	if (tab)
	{
		while (ft_strncmp(tab[len], str, ft_strlen(str, 0)) && tab[len])
			len++;
		if (!tab[len] && str)
			return (0);
	}
	return (len);
}

size_t	ft_nbrlen(int nbr)
{
	size_t	len;

	len = 1;
	if (nbr == -2147483648)
		nbr++;
	if (nbr < 0 && ++len)
		nbr *= -1;
	while (nbr > 9 && ++len)
		nbr = nbr / 10;
	return (len);
}

size_t	ft_unbrlen(size_t nbr)
{
	size_t	len;

	len = 1;
	while (nbr > 9 && ++len)
		nbr = nbr / 10;
	return (len);
}
