/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_key_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:19:59 by corellan          #+#    #+#             */
/*   Updated: 2023/04/24 20:30:22 by tpoho            ###   ########.fr       */
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
		if(cub3d->map_2d_array[(int)(cub3d->player_position_x + cub3d->player_direction_x * MOVEMENT_SPEED)][(int)(cub3d->player_position_y )] == 0)
			cub3d->player_position_x += cub3d->player_direction_x * MOVEMENT_SPEED;
      	if(cub3d->map_2d_array[(int)(cub3d->player_position_x)]
			[(int)(cub3d->player_position_y + cub3d->player_direction_y * MOVEMENT_SPEED)] == 0)
			cub3d->player_position_y += cub3d->player_direction_y * MOVEMENT_SPEED;
	}
	if (key_code == KEY_S)
	{
		if(cub3d->map_2d_array[(int)(cub3d->player_position_x - cub3d->player_direction_x * MOVEMENT_SPEED)][(int)(cub3d->player_position_y)] == 0)
			cub3d->player_position_x -= cub3d->player_direction_x * MOVEMENT_SPEED;
      	if(cub3d->map_2d_array[(int)(cub3d->player_position_x)]
			[(int)(cub3d->player_position_y - cub3d->player_direction_y * MOVEMENT_SPEED)] == 0)
			cub3d->player_position_y -= cub3d->player_direction_y * MOVEMENT_SPEED;
	}
	/*
	if (key_code == KEY_A)
	{
		// strafe do later
	}
	if (key_code == KEY_D)
	{
		// strafe do later
	}
	*/
	if (key_code == KEY_RIGHT)
	{
		temp_direction_x = cub3d->player_direction_x;
		cub3d->player_direction_x = cub3d->player_direction_x * cos(-TURNING_SPEED) - cub3d->player_direction_y * sin(-TURNING_SPEED);
		cub3d->player_direction_y = temp_direction_x * sin(-TURNING_SPEED) + cub3d->player_direction_y * cos(-TURNING_SPEED);
      	temp_camera_plane_x = cub3d->camera_plane_x;
		cub3d->camera_plane_x = cub3d->camera_plane_x * cos(-TURNING_SPEED) - cub3d->camera_plane_y * sin(-TURNING_SPEED);
		cub3d->camera_plane_y = temp_camera_plane_x * sin(-TURNING_SPEED) + cub3d->camera_plane_y * cos(-TURNING_SPEED);
	}
	if (key_code == KEY_LEFT)
	{
		temp_direction_x = cub3d->player_direction_x;
		cub3d->player_direction_x = cub3d->player_direction_x * cos(TURNING_SPEED) - cub3d->player_direction_y * sin(TURNING_SPEED);
		cub3d->player_direction_y = temp_direction_x * sin(TURNING_SPEED) + cub3d->player_direction_y * cos(TURNING_SPEED);
		temp_camera_plane_x = cub3d->camera_plane_x;
		cub3d->camera_plane_x = cub3d->camera_plane_x * cos(TURNING_SPEED) - cub3d->camera_plane_y * sin(TURNING_SPEED);
		cub3d->camera_plane_y = temp_camera_plane_x * sin(TURNING_SPEED) + cub3d->camera_plane_y * cos(TURNING_SPEED);
	}
	//printf("player position: x and y: %f %f\n", cub3d->player_position_x, cub3d->player_position_y);
	//printf("player direction: x and y: %f %f\n", cub3d->player_direction_x, cub3d->player_direction_y);


	return (0);
}
