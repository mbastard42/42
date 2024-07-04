/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <mbastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 21:24:26 by mbastard          #+#    #+#             */
/*   Updated: 2022/03/21 21:03:25 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_get_next_line(int fd)
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
