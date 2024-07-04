/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <mbastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:29:40 by mbastard          #+#    #+#             */
/*   Updated: 2022/04/01 19:00:36 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *src)
{
	char	*dst;

	dst = (char *)ft_calloc(ft_strlen(src, 0) + 1, sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, src, ft_strlen(src, 0) + 1);
	return (dst);
}

char	*ft_substr(const char *src, size_t start, size_t len)
{
	char	*dst;

	if (src == NULL)
		return (NULL);
	if (len > ft_strlen(src, 0))
		len = ft_strlen(src, 0);
	if (start >= ft_strlen(src, 0))
		len = 0;
	dst = (char *)ft_calloc(len + 1, sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, &src[start], len + 1);
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2, int clean_s1, int clean_s2)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	s1_len;
	unsigned long	s2_len;
	char			*dst;

	i = -1;
	j = -1;
	s1_len = ft_strlen(s1, 0);
	s2_len = ft_strlen(s2, 0);
	if (!s1_len && !s2_len)
		return (NULL);
	dst = (char *)ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (dst == NULL)
		return (NULL);
	while (s1_len && s1[++i])
		dst[i] = s1[i];
	while (s2_len && s2[++j])
		dst[s1_len + j] = s2[j];
	dst[s1_len + s2_len] = 0;
	if (clean_s1)
		free(s1);
	if (clean_s2)
		free(s2);
	return (dst);
}

char	*ft_multijoin(char *clean, ...)
{
	size_t	i;
	char	*dst;
	va_list	arg;

	i = -1;
	dst = NULL;
	va_start(arg, clean);
	while (clean[++i])
		dst = ft_strjoin(dst, va_arg(arg, char *), 1, clean[i] - '0');
	va_end(arg);
	return (dst);
}
