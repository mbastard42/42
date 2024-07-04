/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <mbastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 01:37:06 by mbastard          #+#    #+#             */
/*   Updated: 2022/04/26 13:51:47 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# include <mlx.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"

typedef struct s_data {
	void	*mlx;
	void	*win;
	int		key;

	char	**map;
	int		*x_ends;
	int		*y_ends;

	size_t	ends;
	size_t	coins;
	size_t	points;
	size_t	moves;

	void	*img[16];
	int		last;
}			t_data;

//		destroy_data,c functions

void	destroy_map(t_data *d);
void	destroy_mlx(t_data *d);
void	destroy_imgs(t_data *d);
void	destroy_ends(t_data *d);

//		display.c functions

void	display_img(t_data *d);
void	refresh_img(t_data *d, size_t y, size_t x);
void	display_player(t_data *d, size_t y, size_t x);
void	display_map(t_data *d, size_t y, size_t x);
void	display_score(t_data *d);

//		init_data.c functions

void	init_data(t_data *d, char *map_path);
void	init_map(t_data *d, int map_fd);
void	init_imgs(t_data *d);
void	init_count(t_data *d);
void	init_ends(t_data *d);

//		main.c functions

void	quit(t_data *d, char *error_message, int clean);
int		simple_quit(t_data *d);

//		move.c functions

int		get_keycode(int keycode, t_data *d);
void	check_collision_box(t_data *d);
void	move(t_data *d, size_t mv_y, size_t mv_x);

//		parsing.c functions

void	check_map_format(t_data *d, char *map_str);
void	check_map_content(t_data *d);
void	check_imgs(t_data *d);

//		utils.c functions

void	*mlx_xpm_to_img(t_data *d, char *path);
int		mlx_put_img(t_data *d, void *img_ptr, int x, int y);
int		mlx_put_str(t_data *d, int x, int y, char *str);

#endif
