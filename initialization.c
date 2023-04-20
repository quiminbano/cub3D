/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:55:11 by tpoho             #+#    #+#             */
/*   Updated: 2023/04/20 14:01:17 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	mlx_initialization(t_cub3d *cub3d)
{
	cub3d->mlx.mlx = mlx_init();
	cub3d->mlx.mlx_window = mlx_new_window(cub3d->mlx.mlx,
			WIDTH_WINDOW, HEIGHT_WINDOW, "cub3D");
	cub3d->image_1.image = mlx_new_image(cub3d->mlx.mlx,
			WIDTH_WINDOW, HEIGHT_WINDOW);
	cub3d->image_1.address = mlx_get_data_addr(cub3d->image_1.image,
			&cub3d->image_1.bits_per_pixel, &cub3d->image_1.line_length,
			&cub3d->image_1.endianness);
	cub3d->image_2.image = mlx_new_image(cub3d->mlx.mlx,
			WIDTH_WINDOW, HEIGHT_WINDOW);
	cub3d->image_2.address = mlx_get_data_addr(cub3d->image_2.image,
			&cub3d->image_2.bits_per_pixel, &cub3d->image_2.line_length,
			&cub3d->image_2.endianness);
	mlx_loop_hook(cub3d->mlx.mlx, &game_loop, &cub3d->mlx);
	mlx_hook(cub3d->mlx.mlx_window, 2, 0, &key_down_event, &cub3d->mlx);
	mlx_hook(cub3d->mlx.mlx_window, 17, 0, &destroy, &cub3d->mlx);
	mlx_loop(cub3d->mlx.mlx);
}

void	initialization(int argc, char **argv, t_cub3d *cub3d)
{
	// map_initialization
	// can start this function
	// If valid map then load it to cub3d
	// and continue initialization
	// othervise exit
	(void) argc;
	(void) argv;

	cub3d->which_image = 0;
	cub3d->colour_ceiling = 0x000000FF; // Blue
	cub3d->colour_floor = 0x0000FF00; // Green
	mlx_initialization(cub3d);
}
