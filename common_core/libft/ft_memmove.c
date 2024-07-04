/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:29:07 by mbastard          #+#    #+#             */
/*   Updated: 2021/11/03 17:04:00 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long	i;

	i = -1;
	if ((dst || src) && dst > src)
		ft_memcpy(dst, src, len);
	if ((dst || src) && dst < src)
		while (++i < len)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	return (dst);
}
