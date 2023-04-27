/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:13:48 by tpoho             #+#    #+#             */
/*   Updated: 2023/04/27 15:15:19 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	compute_wall_height_and_half_height(t_cub3d *cub3d)
{
	cub3d->render_walls.wall_height
		= (int)(HEIGHT_WINDOW / cub3d->render_walls.straight_wall_distance);
	cub3d->render_walls.wall_height_half
		= cub3d->render_walls.wall_height / 2;
}

static void	compute_y_height_limits_for_wall(t_cub3d *cub3d)
{
	cub3d->render_walls.draw_limit_low
		= -cub3d->render_walls.wall_height_half + HEIGHT_WINDOW_HALF;
	if (cub3d->render_walls.draw_limit_low < 0)
		cub3d->render_walls.draw_limit_low = 0;
	cub3d->render_walls.draw_limit_high
		= cub3d->render_walls.wall_height_half + HEIGHT_WINDOW_HALF;
	if (cub3d->render_walls.draw_limit_high >= HEIGHT_WINDOW)
		cub3d->render_walls.draw_limit_high = HEIGHT_WINDOW - 1;
}

void	draw_window(t_cub3d *cub3d, int x_coord)
{
	int	y_coord;

	compute_wall_height_and_half_height(cub3d);
	compute_y_height_limits_for_wall(cub3d);
	y_coord = cub3d->render_walls.draw_limit_low;
	while (y_coord <= cub3d->render_walls.draw_limit_high)
	{
		if (cub3d->render_walls.which_side_hit == 1)
			put_pixel_in_image(cub3d, x_coord, y_coord, cub3d->colour_wall2);
		else
			put_pixel_in_image(cub3d, x_coord, y_coord, cub3d->colour_wall);
		++y_coord;
	}
}
