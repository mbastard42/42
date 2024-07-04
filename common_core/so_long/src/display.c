/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <mbastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 00:16:52 by mbastard          #+#    #+#             */
/*   Updated: 2022/04/21 18:20:58 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_img(t_data *d)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (d->map[++y])
	{
		x = -1;
		while (d->map[y][++x])
		{
			if (d->map[y][x] == 'P')
				display_player(d, y * 58, x * 58);
			if (ft_strchr("EC01", d->map[y][x], 0))
				display_map(d, y * 58, x * 58);
		}
	}
	display_score(d);
}

void	refresh_img(t_data *d, size_t y, size_t x)
{
	if (d->map[y][x] == 'P')
		display_player(d, y * 58, x * 58);
	if (ft_strchr("EC01", d->map[y][x], 0))
		display_map(d, y * 58, x * 58);
	display_score(d);
}

void	display_player(t_data *d, size_t y, size_t x)
{
	if (d->last == 2)
	{
		mlx_put_img(d, d->img[0], x, y);
		d->last = 0;
	}
	else if (d->key == 1 && !d->last)
		mlx_put_img(d, d->img[0 + d->last++], x, y);
	else if (d->key == 1 && d->last)
		mlx_put_img(d, d->img[0 + d->last--], x, y);
	else if (d->key == 2 && !d->last)
		mlx_put_img(d, d->img[2 + d->last++], x, y);
	else if (d->key == 2 && d->last)
		mlx_put_img(d, d->img[2 + d->last--], x, y);
	else if (d->key == 13 && !d->last)
		mlx_put_img(d, d->img[4 + d->last++], x, y);
	else if (d->key == 13 && d->last)
		mlx_put_img(d, d->img[4 + d->last--], x, y);
	else if (d->key == 0 && !d->last)
		mlx_put_img(d, d->img[6 + d->last++], x, y);
	else if (d->key == 0 && d->last)
		mlx_put_img(d, d->img[6 + d->last--], x, y);
}

void	display_map(t_data *d, size_t y, size_t x)
{
	if (d->map[y / 58][x / 58] == '0')
		mlx_put_img(d, d->img[8], x, y);
	if (d->map[y / 58][x / 58] == '1')
		mlx_put_img(d, d->img[9], x, y);
	if (d->map[y / 58][x / 58] == 'C')
		mlx_put_img(d, d->img[10], x, y);
	if (d->map[y / 58][x / 58] == 'E' && d->points == d->coins)
		mlx_put_img(d, d->img[12], x, y);
	if (d->map[y / 58][x / 58] == 'E' && d->points != d->coins)
		mlx_put_img(d, d->img[11], x, y);
}

void	display_score(t_data *d)
{
	size_t	y;
	size_t	x;
	char	*moves;
	char	*coins;

	y = 0;
	x = 0;
	while (d->map[y])
		y++;
	mlx_put_img(d, d->img[14], x * 58, y * 58);
	while (++x < ft_strlen(d->map[0], 0) - 1)
		mlx_put_img(d, d->img[15], x * 58, y * 58);
	mlx_put_img(d, d->img[13], x * 58, y * 58);
	moves = ft_itoa(d->moves);
	x = x * 58 - ft_strlen(moves, 0) * 9 + 45;
	y = y * 58 + 3;
	mlx_put_str(d, x, y, moves);
	free(moves);
	coins = ft_multijoin("101", ft_itoa(d->points), "/", ft_itoa(d->coins));
	mlx_put_str(d, 10, y, coins);
	free(coins);
}
