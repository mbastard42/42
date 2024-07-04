/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <mbastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:05:18 by mbastard          #+#    #+#             */
/*   Updated: 2022/04/21 18:22:25 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*mlx_xpm_to_img(t_data *d, char *path)
{
	int	tmp;

	return (mlx_xpm_file_to_image(d->mlx, path, &tmp, &tmp));
}

int	mlx_put_img(t_data *d, void *img_ptr, int x, int y)
{
	return (mlx_put_image_to_window(d->mlx, d->win, img_ptr, x, y));
}

int	mlx_put_str(t_data *d, int x, int y, char *str)
{
	return (mlx_string_put(d->mlx, d->win, x, y, 0x0EFE025, str));
}
