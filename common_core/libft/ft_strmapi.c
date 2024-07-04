/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:16:49 by mbastard          #+#    #+#             */
/*   Updated: 2021/11/25 17:16:53 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*d;

	i = -1;
	if (!s || !f)
		return ((char *)s);
	d = ft_strdup(s);
	if (!d)
		return (NULL);
	while (s[++i])
		d[i] = f(i, s[i]);
	return (d);
}
