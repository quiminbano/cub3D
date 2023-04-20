/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_key_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:19:59 by corellan          #+#    #+#             */
/*   Updated: 2023/04/20 19:49:15 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_down_event(int key_code, t_cub3d *cub3d)
{
	double	temp_direction_x;
	double	temp_camera_plane_x;

	// For testing purpose
	printf("Key code: %d\n", key_code);

	if (key_code == KEY_ESC)
		destroy((cub3d));
	if (key_code == KEY_W)
	{
		if (cub3d->map_2d_array[(int)(cub3d->player_position_x
				+ cub3d->player_direction_x * MOVEMENT_SPEED
				+ PLAYER_COLLISION_DISTANCE)]
			[(int)(cub3d->player_position_y)] == EMPTY_SQUARE)
		{
			cub3d->player_position_x
				+= cub3d->player_direction_x * MOVEMENT_SPEED;
		}
		if (cub3d->map_2d_array[(int)(cub3d->player_position_x)]
			[(int)(cub3d->player_position_y + cub3d->player_direction_y
				* MOVEMENT_SPEED + PLAYER_COLLISION_DISTANCE)] == EMPTY_SQUARE)
		{
			cub3d->player_position_y
				+= cub3d->player_direction_y * MOVEMENT_SPEED;
		}
	}
	if (key_code == KEY_S)
	{
		if (cub3d->map_2d_array[(int)(cub3d->player_position_x
				- cub3d->player_direction_x * MOVEMENT_SPEED
				- PLAYER_COLLISION_DISTANCE)]
			[(int)(cub3d->player_position_y)] == EMPTY_SQUARE)
		{
			cub3d->player_position_x
				-= cub3d->player_direction_x * MOVEMENT_SPEED;
		}
		if (cub3d->map_2d_array[(int)(cub3d->player_position_x)]
			[(int)(cub3d->player_position_y - cub3d->player_direction_y
				* MOVEMENT_SPEED - PLAYER_COLLISION_DISTANCE)] == EMPTY_SQUARE)
		{
			cub3d->player_position_y
				-= cub3d->player_direction_y * MOVEMENT_SPEED;
		}
	}
	if (key_code == KEY_RIGHT)
	{
		// Player direction
		temp_direction_x = cub3d->player_direction_x;
		cub3d->player_direction_x
			= cub3d->player_direction_x * cos(-TURNING_SPEED)
			- cub3d->player_direction_y * sin(-TURNING_SPEED);
		cub3d->player_direction_y
			= temp_direction_x * sin(-TURNING_SPEED)
			+ cub3d->player_direction_y * cos(-TURNING_SPEED);

		// Camera direction
		temp_camera_plane_x = cub3d->camera_plane_x;
		cub3d->camera_plane_x
			= cub3d->camera_plane_x * cos(-TURNING_SPEED)
			- cub3d->camera_plane_y * sin(-TURNING_SPEED);
		cub3d->camera_plane_y
			= temp_camera_plane_x * sin(-TURNING_SPEED)
			+ cub3d->camera_plane_y * cos(-TURNING_SPEED);
	}
	if (key_code == KEY_LEFT)
	{
		// Player direction
		temp_direction_x = cub3d->player_direction_x;
		cub3d->player_direction_x
			= cub3d->player_direction_x * cos(TURNING_SPEED)
			- cub3d->player_direction_y * sin(TURNING_SPEED);
		cub3d->player_direction_y
			= temp_direction_x * sin(TURNING_SPEED)
			+ cub3d->player_direction_y * cos(TURNING_SPEED);

		// Camera direction
		temp_camera_plane_x = cub3d->camera_plane_x;
		cub3d->camera_plane_x
			= cub3d->camera_plane_x * cos(TURNING_SPEED)
			- cub3d->camera_plane_y * sin(TURNING_SPEED);
		cub3d->camera_plane_y
			= temp_camera_plane_x * sin(TURNING_SPEED)
			+ cub3d->camera_plane_y * cos(TURNING_SPEED);
	}
	return (0);
}
