/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <mbastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:27:28 by mbastard          #+#    #+#             */
/*   Updated: 2022/04/26 13:47:33 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_data(t_data *d, char *map_path)
{
	int			map_fd;
	size_t		y;
	size_t		x;

	map_fd = open(map_path, O_RDONLY);
	init_map(d, map_fd);
	y = 0;
	while (d->map[y])
		y++;
	x = ft_strlen(d->map[0], 0);
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, x * 58, y * 58 + 30, "so_long");
	init_imgs(d);
	init_count(d);
	init_ends(d);
	close(map_fd);
}

void	init_map(t_data *d, int map_fd)
{
	char	*line;
	char	*map_str;

	map_str = NULL;
	line = ft_mini_gnl(map_fd);
	if (!line)
		quit(d, "Error\nCouldn't access map\n", 0);
	map_str = ft_strjoin(map_str, line, 1, 1);
	while (line)
	{
		line = ft_mini_gnl(map_fd);
		map_str = ft_strjoin(map_str, line, 1, 1);
	}
	d->map = ft_split(map_str, '\n');
	check_map_format(d, map_str);
	check_map_content(d);
	free(map_str);
}

void	init_imgs(t_data *d)
{
	d->last = 2;
	d->img[0] = mlx_xpm_to_img(d, "img/P1.xpm");
	d->img[1] = mlx_xpm_to_img(d, "img/P2.xpm");
	d->img[2] = mlx_xpm_to_img(d, "img/P3.xpm");
	d->img[3] = mlx_xpm_to_img(d, "img/P4.xpm");
	d->img[4] = mlx_xpm_to_img(d, "img/P5.xpm");
	d->img[5] = mlx_xpm_to_img(d, "img/P6.xpm");
	d->img[6] = mlx_xpm_to_img(d, "img/P7.xpm");
	d->img[7] = mlx_xpm_to_img(d, "img/P8.xpm");
	d->img[8] = mlx_xpm_to_img(d, "img/0.xpm");
	d->img[9] = mlx_xpm_to_img(d, "img/1.xpm");
	d->img[10] = mlx_xpm_to_img(d, "img/C.xpm");
	d->img[11] = mlx_xpm_to_img(d, "img/E1.xpm");
	d->img[12] = mlx_xpm_to_img(d, "img/E2.xpm");
	d->img[13] = mlx_xpm_to_img(d, "img/r.xpm");
	d->img[14] = mlx_xpm_to_img(d, "img/l.xpm");
	d->img[15] = mlx_xpm_to_img(d, "img/m.xpm");
	check_imgs(d);
}

void	init_count(t_data *d)
{
	size_t	y;
	size_t	x;

	y = -1;
	d->moves = 0;
	d->coins = 0;
	d->points = 0;
	while (d->map[++y])
	{
		x = -1;
		while (d->map[y][++x])
		{
			if (d->map[y][x] == 'C')
				d->coins++;
			if (d->map[y][x] == 'E')
				d->ends++;
		}
	}
}

void	init_ends(t_data *d)
{
	int	i;
	int	y;
	int	x;

	i = -1;
	y = -1;
	d->y_ends = (int *)ft_calloc(d->ends, sizeof(int));
	d->x_ends = (int *)ft_calloc(d->ends, sizeof(int));
	while (d->map[++y])
	{
		x = -1;
		while (d->map[y][++x])
		{
			if (d->map[y][x] == 'E')
			{
				d->y_ends[++i] = y;
				d->x_ends[i] = x;
			}
		}
	}
}
