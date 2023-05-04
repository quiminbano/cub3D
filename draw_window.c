/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:13:48 by tpoho             #+#    #+#             */
/*   Updated: 2023/05/04 14:37:40 by tpoho            ###   ########.fr       */
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
	//if (cub3d->render_walls.draw_limit_low < 0)
		//cub3d->render_walls.draw_limit_low = 0;
	cub3d->render_walls.draw_limit_high
		= cub3d->render_walls.wall_height_half + HEIGHT_WINDOW_HALF;
	//if (cub3d->render_walls.draw_limit_high >= HEIGHT_WINDOW)
		//cub3d->render_walls.draw_limit_high = HEIGHT_WINDOW - 1;
}

// N = 0, S = 1, W = 2, E = 3
int	which_wall_side(t_cub3d *cub3d)
{
	if (cub3d->render_walls.which_side_hit == 0)
	{
		if (cub3d->render_walls.ray_direction_x > 0)
			return (2);
		else
			return (3);
	}
	if (cub3d->render_walls.ray_direction_y > 0)
		return (1);
	else
		return (0);
}

int	relative_hight_texture(t_cub3d *cub3d, int y_coord)
{
	return ((int)((((double) y_coord - cub3d->render_walls.draw_limit_low)
			/ (cub3d->render_walls.draw_limit_high
				- cub3d->render_walls.draw_limit_low))
		* cub3d->texture_height));
}

double	exact_coord_x_for_wall(t_cub3d *cub3d)
{
	double	exact_wall_x_coord;

	exact_wall_x_coord = cub3d->player_position_x
		+ cub3d->render_walls.straight_wall_distance
		* cub3d->render_walls.ray_direction_x;
	if (cub3d->render_walls.which_side_hit == 0)
	{
		exact_wall_x_coord = cub3d->player_position_y
			+ cub3d->render_walls.straight_wall_distance
			* cub3d->render_walls.ray_direction_y;
	}
	exact_wall_x_coord -= floor((exact_wall_x_coord));
	return (exact_wall_x_coord);
}

void	determine_texture_pixel_colours(t_cub3d *cub3d,
	int y_coord, int x_coord)
{
	double	exact_wall_x_coord;
	int		texture_x_coord;
	int		which_nswe;	
	int		texture_colour;

	exact_wall_x_coord = exact_coord_x_for_wall(cub3d);
	which_nswe = which_wall_side(cub3d);
	texture_x_coord = (int)(exact_wall_x_coord
			* ((double) cub3d->texture_width));
	if (cub3d->render_walls.which_side_hit == 0
		&& cub3d->render_walls.ray_direction_x > 0)
		texture_x_coord = cub3d->texture_width - texture_x_coord - 1;
	if (cub3d->render_walls.which_side_hit == 1
		&& cub3d->render_walls.ray_direction_y < 0)
		texture_x_coord = cub3d->texture_width - texture_x_coord - 1;
	while (y_coord <= cub3d->render_walls.draw_limit_high)
	{
		texture_colour = cub3d->textures[which_nswe]
		[relative_hight_texture(cub3d, y_coord)
			* cub3d->texture_width + texture_x_coord];
		put_pixel_in_image(cub3d, x_coord, y_coord, texture_colour);
		++y_coord;
	}
}

void	draw_window(t_cub3d *cub3d, int x_coord)
{
	int	y_coord;

	compute_wall_height_and_half_height(cub3d);
	compute_y_height_limits_for_wall(cub3d);
	y_coord = cub3d->render_walls.draw_limit_low;
	determine_texture_pixel_colours(cub3d, y_coord, x_coord);
}
