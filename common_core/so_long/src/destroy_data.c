/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <mbastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:09:18 by mbastard          #+#    #+#             */
/*   Updated: 2022/04/21 18:35:02 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_map(t_data *d)
{
	int	i;

	i = -1;
	while (d->map[++i])
		free(d->map[i]);
	free(d->map[i]);
	free(d->map);
}

void	destroy_mlx(t_data *d)
{
	mlx_destroy_window(d->mlx, d->win);
}

void	destroy_imgs(t_data *d)
{
	int	i;

	i = -1;
	while (++i <= 15 && d->img[i])
		mlx_destroy_image(d->mlx, d->img[i]);
}

void	destroy_ends(t_data *d)
{
	free(d->y_ends);
	free(d->x_ends);
}
