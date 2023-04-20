/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:57:56 by tpoho             #+#    #+#             */
/*   Updated: 2023/04/20 19:49:08 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_loop(t_cub3d *cub3d)
{
	
	
	render_floor_ceiling(cub3d);

	if (cub3d->which_image == 0)
		mlx_put_image_to_window(cub3d->mlx.mlx,
			cub3d->mlx.mlx_window, cub3d->image_1.image, 0, 0);
	else
		mlx_put_image_to_window(cub3d->mlx.mlx,
			cub3d->mlx.mlx_window, cub3d->image_2.image, 0, 0);
	
	// Test flickering warning epilepsy 
	/*
	if (cub3d->which_image == 1)
	{
		cub3d->colour_ceiling = 0x000000FF; // Blue
		cub3d->colour_floor = 0x0000FF00; // Green
	}
	if (cub3d->which_image == 0)
	{
		cub3d->colour_ceiling = 0x0000FF00; // Green
		cub3d->colour_floor = 0x00FF0000; // RED
	}
	*/
	
	cub3d->which_image = (cub3d->which_image + 1) % 2; // image change 0 -> 1 and 1 -> 0
	return (0);
}
