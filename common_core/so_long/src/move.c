/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <mbastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 00:16:15 by mbastard          #+#    #+#             */
/*   Updated: 2022/04/21 19:06:46 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_keycode(int keycode, t_data *d)
{
	d->key = keycode;
	if ((d->key >= 0 && d->key <= 2) || d->key == 13)
		check_collision_box(d);
	if (d->key == 53)
		quit(d, NULL, 4);
	return (0);
}

void	check_collision_box(t_data *d)
{
	size_t	y;
	size_t	x;
	size_t	mv_y;
	size_t	mv_x;

	y = 0;
	while (d->map[y] && !ft_strlen(d->map[y], 'P'))
		y++;
	x = ft_strlen(d->map[y], 'P');
	mv_y = 0;
	mv_x = 0;
	if (d->key == 13 || d->key == 1)
		mv_y = -1 * (d->key - 2) / 11 + 1 / d->key;
	if (d->key == 0 || d->key == 2)
		mv_x = d->key - 1;
	if (d->map[y + mv_y][x + mv_x] != '1')
	{
		if (d->map[y + mv_y][x + mv_x] != 'E')
			move(d, mv_y, mv_x);
		else if (d->points == d->coins)
			quit(d, NULL, 4);
	}
}

void	move(t_data *d, size_t mv_y, size_t mv_x)
{
	int			i;
	size_t		y;
	size_t		x;

	i = -1;
	y = 0;
	while (d->map[y] && !ft_strlen(d->map[y], 'P'))
		y++;
	x = ft_strlen(d->map[y], 'P');
	if (d->map[y + mv_y][x + mv_x] == 'C')
		d->points++;
	d->map[y + mv_y][x + mv_x] = 'P';
	d->map[y][x] = '0';
	d->moves++;
	refresh_img(d, y, x);
	refresh_img(d, y + mv_y, x + mv_x);
	while (++i < (int)d->ends)
		refresh_img(d, d->y_ends[i], d->x_ends[i]);
	display_score(d);
}
