/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <mbastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:15:47 by mbastard          #+#    #+#             */
/*   Updated: 2022/03/21 21:03:42 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
	return (ft_strlen(src, 0));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	j = 0;
	while (dst[i] && dstsize - i)
		i++;
	if (dstsize - i)
	{
		while (src[j] && (dstsize - i - 1))
			dst[i++] = src[j++];
		dst[i] = 0;
	}
	return (i - j + ft_strlen(src, 0));
}

char	*ft_strtrim(char *src, char const *set, int clean_src)
{
	unsigned long	start;
	unsigned long	end;
	char			*dst;

	if (src == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(src, 0);
	while (ft_strchr(set, src[start], 0) && src[start])
		start++;
	if (start == ft_strlen(src, 0))
		return (NULL);
	while (ft_strchr(set, src[end], 0) && end)
		end--;
	if (end)
		end = ft_strlen(src, 0) - end - 1;
	dst = (char *)ft_calloc(ft_strlen(src, 0) - start - end + 1, sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, &src[start], ft_strlen(src, 0) - start - end + 1);
	if (clean_src)
		free(src);
	return (dst);
}
