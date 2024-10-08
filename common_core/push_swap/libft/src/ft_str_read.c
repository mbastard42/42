/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <mbastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:29:31 by mbastard          #+#    #+#             */
/*   Updated: 2022/03/21 21:03:40 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *str, char c, int gap)
{
	int	i;

	i = -1;
	if (str)
		while (str[++i])
			if (str[i] == c)
				return ((char *)&str[i + gap]);
	return (NULL);
}

char	*ft_strrchr(const char *str, char c, int gap)
{
	int	i;

	i = ft_strlen(str, 0);
	while (str[i] != c && i)
		i--;
	if (i)
		return ((char *)&str[i + gap]);
	return (NULL);
}

char	*ft_strnstr(const char *str, const char *sub, size_t n)
{
	size_t	i;
	size_t	j;

	i = -1;
	if (n > ft_strlen(str, 0))
		n = ft_strlen(str, 0);
	while (++i <= n)
	{
		j = 0;
		while (str[i + j] == sub[j] && sub[j] && (n - i - j))
			j++;
		if (!sub[j])
			return ((char *)&str[i]);
	}
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] == s2[i] && s1[i] && s2[i] && n--)
		i++;
	if (n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
