/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbastard <mbastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 00:16:34 by mbastard          #+#    #+#             */
/*   Updated: 2022/04/26 13:51:19 by mbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_data	d;

	if (argc != 2)
		quit(&d, "Error\nYou must choose one map\n", 0);
	if (!ft_strnstr(&argv[1][ft_strlen(argv[1], 0) - 4], ".ber", 4))
		quit(&d, "Error\nMap must be a .ber file\n", 0);
	init_data(&d, argv[argc - 1]);
	display_img(&d);
	mlx_hook(d.win, 2, 0, &get_keycode, &d);
	mlx_hook(d.win, 17, 0, &simple_quit, &d);
	mlx_loop(d.mlx);
	return (0);
}

void	quit(t_data *d, char *error_message, int clean)
{
	if (clean >= 1)
		destroy_map(d);
	if (clean >= 2)
	{
		if (clean >= 3)
			destroy_imgs(d);
		if (clean >= 4)
			destroy_ends(d);
		destroy_mlx(d);
	}
	if (error_message)
		ft_putstr_fd(1, error_message);
	exit(0);
}

int	simple_quit(t_data *d)
{
	quit(d, NULL, 4);
	return (0);
}
