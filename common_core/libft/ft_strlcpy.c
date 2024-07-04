/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:29:59 by mbastard          #+#    #+#             */
/*   Updated: 2021/11/03 15:30:01 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned long	i;

	i = -1;
	if (dstsize - i - 1)
	{
		while (src[++i] && (dstsize - i - 1))
			dst[i] = src[i];
		dst[i] = 0;
	}
	return (ft_strlen(src));
}
