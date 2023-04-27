/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:48:53 by tpoho             #+#    #+#             */
/*   Updated: 2023/04/27 15:33:16 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_cub3d *cub3d)
{
	if (cub3d->map_2d_array[(int)(cub3d->player_position_x
			+ cub3d->player_direction_x * MOVEMENT_SPEED)]
		[(int)(cub3d->player_position_y)] == 0)
		cub3d->player_position_x += cub3d->player_direction_x * MOVEMENT_SPEED;
	if (cub3d->map_2d_array[(int)(cub3d->player_position_x)]
		[(int)(cub3d->player_position_y
		+ cub3d->player_direction_y * MOVEMENT_SPEED)] == 0)
		cub3d->player_position_y += cub3d->player_direction_y * MOVEMENT_SPEED;
}

void	move_backward(t_cub3d *cub3d)
{
	if (cub3d->map_2d_array[(int)(cub3d->player_position_x
			- cub3d->player_direction_x * MOVEMENT_SPEED)]
			[(int)(cub3d->player_position_y)] == 0)
		cub3d->player_position_x -= cub3d->player_direction_x * MOVEMENT_SPEED;
	if (cub3d->map_2d_array[(int)(cub3d->player_position_x)]
			[(int)(cub3d->player_position_y
			- cub3d->player_direction_y * MOVEMENT_SPEED)] == 0)
		cub3d->player_position_y -= cub3d->player_direction_y * MOVEMENT_SPEED;
}

void	strafe_left(t_cub3d *cub3d)
{
	if (cub3d->map_2d_array[(int)(cub3d->player_position_x
			+ (-cub3d->camera_plane_x * MOVEMENT_SPEED * 1.5))]
		[(int)(cub3d->player_position_y)] == 0)
		cub3d->player_position_x
			+= (-cub3d->camera_plane_x * MOVEMENT_SPEED * 1.5);
	if (cub3d->map_2d_array[(int)(cub3d->player_position_x)]
		[(int)(cub3d->player_position_y
		+ (-cub3d->camera_plane_y * MOVEMENT_SPEED * 1.5))] == 0)
		cub3d->player_position_y
			+= (-cub3d->camera_plane_y * MOVEMENT_SPEED * 1.5);
}

void	strafe_right(t_cub3d *cub3d)
{
	if (cub3d->map_2d_array[(int)(cub3d->player_position_x
			+ (cub3d->camera_plane_x * MOVEMENT_SPEED * 1.5))]
		[(int)(cub3d->player_position_y)] == 0)
		cub3d->player_position_x
			+= (cub3d->camera_plane_x * MOVEMENT_SPEED * 1.5);
	if (cub3d->map_2d_array[(int)(cub3d->player_position_x)]
			[(int)(cub3d->player_position_y
			+ (cub3d->camera_plane_y * MOVEMENT_SPEED * 1.5))] == 0)
		cub3d->player_position_y
			+= (cub3d->camera_plane_y * MOVEMENT_SPEED * 1.5);
}