/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:57:56 by tpoho             #+#    #+#             */
/*   Updated: 2023/04/25 21:03:50 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_walls(t_cub3d *cub3d)
{
	int	x_coord;
	int	y_coord;

	y_coord = 0;
	x_coord = 0;
	while (x_coord < WIDTH_WINDOW)
	{
		//calculate ray position and direction
		cub3d->render_walls.ray_coordinate_in_camera_plane
			= (2 * ((double) x_coord / WIDTH_WINDOW)) - 1;
		cub3d->render_walls.ray_direction_x
			= cub3d->player_direction_x + cub3d->camera_plane_x
			* cub3d->render_walls.ray_coordinate_in_camera_plane;
		cub3d->render_walls.ray_direction_y
			= cub3d->player_direction_y + cub3d->camera_plane_y
			* cub3d->render_walls.ray_coordinate_in_camera_plane;

		//which box of the map we're in
		cub3d->render_walls.player_which_map_cell_x
			= (int) cub3d->player_position_x;
		cub3d->render_walls.player_which_map_cell_y
			= (int) cub3d->player_position_y;


		//cub3d->render_walls.delta_distance_to_next_x = 1e30;
		//if (cub3d->render_walls.ray_direction_x != 0)
		cub3d->render_walls.delta_distance_to_next_x = fabs(1 / cub3d->render_walls.ray_direction_x);

		//cub3d->render_walls.delta_distance_to_next_y = 1e30;
		//if (cub3d->render_walls.ray_direction_y != 0)
		cub3d->render_walls.delta_distance_to_next_y = fabs(1 / cub3d->render_walls.ray_direction_y);
		
		cub3d->render_walls.wall_hit = 0;

		//calculate step and initial sideDist
		cub3d->render_walls.take_step_in_x = 1;
			cub3d->render_walls.length_of_ray_to_next_x
			= (cub3d->render_walls.player_which_map_cell_x
				+ 1.0 - cub3d->player_position_x)
			* cub3d->render_walls.delta_distance_to_next_x;
		if (cub3d->render_walls.ray_direction_x < 0)
		{
			cub3d->render_walls.take_step_in_x = -1;
			cub3d->render_walls.length_of_ray_to_next_x
				= (cub3d->player_position_x
					- cub3d->render_walls.player_which_map_cell_x)
				* cub3d->render_walls.delta_distance_to_next_x;
		}

		cub3d->render_walls.take_step_in_y = 1;
			cub3d->render_walls.length_of_ray_to_next_y
			= (cub3d->render_walls.player_which_map_cell_y
				+ 1.0 - cub3d->player_position_y)
			* cub3d->render_walls.delta_distance_to_next_y;
		if (cub3d->render_walls.ray_direction_y < 0)
		{
			cub3d->render_walls.take_step_in_y = -1;
			cub3d->render_walls.length_of_ray_to_next_y
				= (cub3d->player_position_y
					- cub3d->render_walls.player_which_map_cell_y)
				* cub3d->render_walls.delta_distance_to_next_y;
		}

		//perform DDA
		while (cub3d->render_walls.wall_hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if (cub3d->render_walls.length_of_ray_to_next_x
				< cub3d->render_walls.length_of_ray_to_next_y)
			{
				cub3d->render_walls.length_of_ray_to_next_x
					+= cub3d->render_walls.delta_distance_to_next_x;
				cub3d->render_walls.player_which_map_cell_x
					+= cub3d->render_walls.take_step_in_x;
				cub3d->render_walls.which_side_hit = 0;
			}
			else
			{
				cub3d->render_walls.length_of_ray_to_next_y
					+= cub3d->render_walls.delta_distance_to_next_y;
				cub3d->render_walls.player_which_map_cell_y
					+= cub3d->render_walls.take_step_in_y;
				cub3d->render_walls.which_side_hit = 1;
			}

			//Check if ray has hit a wall
				if (cub3d->map_2d_array[cub3d->render_walls.player_which_map_cell_x]
					[cub3d->render_walls.player_which_map_cell_y] > 0)
				cub3d->render_walls.wall_hit = 1;
		}

		
		// one step back
		cub3d->render_walls.straight_wall_distance
				= cub3d->render_walls.length_of_ray_to_next_y
				- cub3d->render_walls.delta_distance_to_next_y;
		if(cub3d->render_walls.which_side_hit == 0)
		{
			cub3d->render_walls.straight_wall_distance
				= cub3d->render_walls.length_of_ray_to_next_x
				- cub3d->render_walls.delta_distance_to_next_x;
		}
		
		//Calculate height of line to draw on screen
		cub3d->render_walls.wall_height
			= (int)(HEIGHT_WINDOW / cub3d->render_walls.straight_wall_distance);
		cub3d->render_walls.wall_height_half
			= cub3d->render_walls.wall_height / 2;

		//calculate lowest and highest pixel to fill in current stripe
		cub3d->render_walls.draw_limit_low = -cub3d->render_walls.wall_height_half + HEIGHT_WINDOW_HALF;
		if(cub3d->render_walls.draw_limit_low < 0)
			cub3d->render_walls.draw_limit_low = 0;
		cub3d->render_walls.draw_limit_high = cub3d->render_walls.wall_height_half + HEIGHT_WINDOW_HALF;
	  	if(cub3d->render_walls.draw_limit_high >= HEIGHT_WINDOW)
	  		cub3d->render_walls.draw_limit_high = HEIGHT_WINDOW - 1;

		//draw the pixels of the stripe as a vertical line
		//verLine(x, drawStart, drawEnd, color);
		
		y_coord = cub3d->render_walls.draw_limit_low;
		/*
		if(cub3d->render_walls.which_side_hit == 1)
			while (y_coord <= cub3d->render_walls.draw_limit_high)
			{
				put_pixel_in_image(cub3d, x_coord, y_coord, cub3d->colour_wall2);
				++y_coord;
			}
		else
		{
			while (y_coord <= cub3d->render_walls.draw_limit_high)
			{
				put_pixel_in_image(cub3d, x_coord,  y_coord, cub3d->colour_wall);
				++y_coord;
			}
		}
		*/
		if(cub3d->render_walls.which_side_hit == 1)
		{
			put_pixel_in_image_2(cub3d, x_coord, y_coord, cub3d->render_walls.draw_limit_high, cub3d->colour_wall2);
		}
		else
		{
			put_pixel_in_image_2(cub3d, x_coord, y_coord, cub3d->render_walls.draw_limit_high, cub3d->colour_wall);
		}
	++x_coord;
	}
}

void	move_character(t_cub3d *cub3d)
{
	double	temp_direction_x;
	double	temp_camera_plane_x;


	if (cub3d->key_w_down == 1)
	{
		if(cub3d->map_2d_array[(int)(cub3d->player_position_x + cub3d->player_direction_x * MOVEMENT_SPEED)][(int)(cub3d->player_position_y )] == 0)
			cub3d->player_position_x += cub3d->player_direction_x * MOVEMENT_SPEED;
      	if(cub3d->map_2d_array[(int)(cub3d->player_position_x)]
			[(int)(cub3d->player_position_y + cub3d->player_direction_y * MOVEMENT_SPEED)] == 0)
			cub3d->player_position_y += cub3d->player_direction_y * MOVEMENT_SPEED;
	}
	if (cub3d->key_s_down == 1)
	{
		if(cub3d->map_2d_array[(int)(cub3d->player_position_x - cub3d->player_direction_x * MOVEMENT_SPEED)][(int)(cub3d->player_position_y)] == 0)
			cub3d->player_position_x -= cub3d->player_direction_x * MOVEMENT_SPEED;
      	if(cub3d->map_2d_array[(int)(cub3d->player_position_x)]
			[(int)(cub3d->player_position_y - cub3d->player_direction_y * MOVEMENT_SPEED)] == 0)
			cub3d->player_position_y -= cub3d->player_direction_y * MOVEMENT_SPEED;
	}
	if (cub3d->key_arrow_right_down == 1)
	{
		temp_direction_x = cub3d->player_direction_x;
		cub3d->player_direction_x = cub3d->player_direction_x * cos(-TURNING_SPEED) - cub3d->player_direction_y * sin(-TURNING_SPEED);
		cub3d->player_direction_y = temp_direction_x * sin(-TURNING_SPEED) + cub3d->player_direction_y * cos(-TURNING_SPEED);
      	temp_camera_plane_x = cub3d->camera_plane_x;
		cub3d->camera_plane_x = cub3d->camera_plane_x * cos(-TURNING_SPEED) - cub3d->camera_plane_y * sin(-TURNING_SPEED);
		cub3d->camera_plane_y = temp_camera_plane_x * sin(-TURNING_SPEED) + cub3d->camera_plane_y * cos(-TURNING_SPEED);
	}
}

int	game_loop(t_cub3d *cub3d)
{
	move_character(cub3d);
	render_floor_ceiling(cub3d);
	render_walls(cub3d);

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
