/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <mbastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:10:40 by mbastard          #+#    #+#             */
/*   Updated: 2022/04/21 18:22:11 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map_format(t_data *d, char *map_str)
{
	int	i;

	i = -1;
	if (ft_strnstr(map_str, "\n\n", ft_strlen(map_str, 0)))
		quit(d, "Error\nMap can't contain consecutive new lines\n", 1);
	while (d->map[++i])
		if (ft_strlen(d->map[i], 0) != ft_strlen(d->map[0], 0))
			quit(d, "Error\nMap must be rectangular\n", 1);
	if (ft_strlen(d->map[0], 0) > (size_t)((1920 / 58) - 1))
		quit(d, "Error\nMap is too wide\n", 1);
	if (ft_tablen(d->map, NULL) > (size_t)((1080 / 58) - 2))
		quit(d, "Error\nMap is too tall\n", 1);
}

void	check_map_content(t_data *d)
{
	size_t	y;
	size_t	x;
	int		count[81];

	y = -1;
	ft_memset(count, 0, 81 * sizeof(int));
	while (d->map[++y])
	{
		x = -1;
		while (d->map[y][++x])
		{
			if (!ft_strchr("01PEC", d->map[y][x], 0))
				quit(d, "Error\nMap contain invalid element\n", 1);
			if ((!x || !y || !d->map[y + 1] || !d->map[y][x + 1]))
				if (d->map[y][x] != '1')
					quit(d, "Error\nMap must be enclosed in walls\n", 1);
			if (ft_strchr("PEC", d->map[y][x], 0))
				count[(int)d->map[y][x]]++;
		}
	}
	if (count['P'] != 1 || count['E'] < 1)
		quit(d, "Error\nMap must contain 1 player and at least one exit\n", 1);
	if (count['C'] < 1)
		quit(d, "Error\nMap must contain at least one collectible\n", 1);
}

void	check_imgs(t_data *d)
{
	int	i;

	i = -1;
	while (++i <= 15)
		if (!d->img[i])
			quit(d, "Error\nCouldn't access images\n", 3);
}
