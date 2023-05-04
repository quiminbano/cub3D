/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:48:53 by tpoho             #+#    #+#             */
/*   Updated: 2023/05/04 14:22:41 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	insert_safety_movement_buffer(t_cub3d *cub3d, int x_or_y, int backward)
{
	if (x_or_y == 0)
	{
		if (cub3d->player_direction_x > 0)
		{
			return (PLAYER_COLLISION_DISTANCE * backward);
		}
		else
			return (-PLAYER_COLLISION_DISTANCE * backward);
	}
	if (x_or_y == 1)
	{
		if (cub3d->player_direction_y > 0)
		{
			return (PLAYER_COLLISION_DISTANCE * backward);
		}
		else
			return (-PLAYER_COLLISION_DISTANCE * backward);
	}
	return (0);
}

double	insert_safety_movement_buffer_strafe(t_cub3d *cub3d,
	int x_or_y, int backward)
{
	if (x_or_y == 0)
	{
		if (cub3d->camera_plane_x > 0)
		{
			return (PLAYER_COLLISION_DISTANCE * backward);
		}
		else
			return (-PLAYER_COLLISION_DISTANCE * backward);
	}
	if (x_or_y == 1)
	{
		if (cub3d->camera_plane_y > 0)
		{
			return (PLAYER_COLLISION_DISTANCE * backward);
		}
		else
			return (-PLAYER_COLLISION_DISTANCE * backward);
	}
	return (0);
}

void	move_forward(t_cub3d *cub3d)
{
	if (cub3d->map_int[(int)(cub3d->player_position_x
			+ cub3d->player_direction_x * MOVEMENT_SPEED
			+ insert_safety_movement_buffer(cub3d, 0, 1))]
		[(int)(cub3d->player_position_y)] == 0)
		cub3d->player_position_x += cub3d->player_direction_x * MOVEMENT_SPEED;
	if (cub3d->map_int[(int)(cub3d->player_position_x)]
		[(int)(cub3d->player_position_y
		+ cub3d->player_direction_y * MOVEMENT_SPEED
		+ insert_safety_movement_buffer(cub3d, 1, 1))] == 0)
		cub3d->player_position_y += cub3d->player_direction_y * MOVEMENT_SPEED;
}

void	move_backward(t_cub3d *cub3d)
{
	//if (cub3d->map_int[(int)(cub3d->player_position_x
	//		- cub3d->player_direction_x * MOVEMENT_SPEED)]
	//		[(int)(cub3d->player_position_y)] == 0)
	//	cub3d->player_position_x -= cub3d->player_direction_x * MOVEMENT_SPEED;
	//if (cub3d->map_int[(int)(cub3d->player_position_x)]
	//		[(int)(cub3d->player_position_y
	//		- cub3d->player_direction_y * MOVEMENT_SPEED)] == 0)
	//	cub3d->player_position_y -= cub3d->player_direction_y * MOVEMENT_SPEED;
	if (cub3d->map_int[(int)(cub3d->player_position_x
			- (cub3d->player_direction_x * MOVEMENT_SPEED)
			+ insert_safety_movement_buffer(cub3d, 0, -1))]
		[(int)(cub3d->player_position_y)] == 0)
		cub3d->player_position_x -= cub3d->player_direction_x * MOVEMENT_SPEED;
	if (cub3d->map_int[(int)(cub3d->player_position_x)]
		[(int)(cub3d->player_position_y
		- (cub3d->player_direction_y * MOVEMENT_SPEED)
		+ insert_safety_movement_buffer(cub3d, 1, -1))] == 0)
		cub3d->player_position_y -= cub3d->player_direction_y * MOVEMENT_SPEED;
}

void	strafe_left(t_cub3d *cub3d)
{
	if (cub3d->map_int[(int)(cub3d->player_position_x
			+ (-cub3d->camera_plane_x * MOVEMENT_SPEED * 1.5)
			+ insert_safety_movement_buffer_strafe(cub3d, 0, -1))]
		[(int)(cub3d->player_position_y)] == 0)
		cub3d->player_position_x
			+= (-cub3d->camera_plane_x * MOVEMENT_SPEED * 1.5);
	if (cub3d->map_int[(int)(cub3d->player_position_x)]
		[(int)(cub3d->player_position_y
		+ (-cub3d->camera_plane_y * MOVEMENT_SPEED * 1.5)
		+ insert_safety_movement_buffer_strafe(cub3d, 1, -1))] == 0)
		cub3d->player_position_y
			+= (-cub3d->camera_plane_y * MOVEMENT_SPEED * 1.5);
}

void	strafe_right(t_cub3d *cub3d)
{
	if (cub3d->map_int[(int)(cub3d->player_position_x
			+ (cub3d->camera_plane_x * MOVEMENT_SPEED * 1.5)
			+ insert_safety_movement_buffer_strafe(cub3d, 0, 1))]
		[(int)(cub3d->player_position_y)] == 0)
		cub3d->player_position_x
			+= (cub3d->camera_plane_x * MOVEMENT_SPEED * 1.5);
	if (cub3d->map_int[(int)(cub3d->player_position_x)]
			[(int)(cub3d->player_position_y
			+ (cub3d->camera_plane_y * MOVEMENT_SPEED * 1.5)
			+ insert_safety_movement_buffer_strafe(cub3d, 1, 1))] == 0)
		cub3d->player_position_y
			+= (cub3d->camera_plane_y * MOVEMENT_SPEED * 1.5);
}
