/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:30:24 by mbastard          #+#    #+#             */
/*   Updated: 2021/11/03 15:30:27 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	i;
	unsigned long	j;

	i = -1;
	j = 0;
	if (len > ft_strlen(haystack))
		len = ft_strlen(haystack);
	while (++i <= len)
	{
		while (haystack[i + j] == needle[j] && needle[j] && (len - i - j))
			j++;
		if (!needle[j])
			return ((char *)&haystack[i]);
		j = 0;
	}
	return (NULL);
}
