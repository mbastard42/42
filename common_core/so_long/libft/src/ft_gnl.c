/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <mbastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 21:24:26 by mbastard          #+#    #+#             */
/*   Updated: 2022/04/21 17:27:43 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_mini_gnl(int fd)
{
	char	*line;
	char	buff[2];

	line = NULL;
	if (fd < 0 || read(fd, buff, 0) < 0)
		return (NULL);
	buff[read(fd, buff, 1)] = 0;
	line = ft_strjoin(line, buff, 1, 0);
	while (ft_strlen(buff, 0) && !(ft_strchr(buff, '\n', 0)))
	{
		buff[read(fd, buff, 1)] = 0;
		line = ft_strjoin(line, buff, 1, 0);
	}
	return (line);
}
