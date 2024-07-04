/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:46:52 by mbastard          #+#    #+#             */
/*   Updated: 2021/11/25 17:10:37 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fill_tab(char **tab, char *s, char c)
{
	unsigned long	i;
	unsigned long	len;
	unsigned long	div;

	i = -1;
	len = 0;
	div = -1;
	while (s[++i])
	{
		if (s[i] != c && ++len && (s[i + 1] == c || !s[i + 1]))
		{
			*tab = ft_substr(s, i - len + 1, len);
			if (!*tab)
			{
				while (tab[++div])
					free(tab[div]);
				free(tab);
			}
			len = 0;
			tab++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	unsigned long	i;
	unsigned long	div;
	char			*buff;
	char			**tab;

	i = -1;
	div = 1;
	buff = ft_strtrim(s, &c);
	if (!buff)
		return (NULL);
	if (ft_strlen(buff))
		div++;
	while (buff[++i])
		if (buff[i] == c && buff[i + 1] != c)
			div++;
	tab = (char **)ft_calloc(div, sizeof(char *));
	if (!tab)
		return (NULL);
	tab[--div] = NULL;
	ft_fill_tab(tab, buff, c);
	free(buff);
	return (tab);
}
