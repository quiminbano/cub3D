/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:55:11 by tpoho             #+#    #+#             */
/*   Updated: 2023/04/25 20:41:42 by tpoho            ###   ########.fr       */
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
	cub3d->put_pixel_in_image_temp = cub3d->image_1.bits_per_pixel / 8;
	mlx_loop_hook(cub3d->mlx.mlx, &game_loop, &cub3d->mlx);
	mlx_hook(cub3d->mlx.mlx_window, 2, 0, &key_down_event, &cub3d->mlx);
	mlx_hook(cub3d->mlx.mlx_window, 3, 0, &key_up_event, &cub3d->mlx);
	mlx_hook(cub3d->mlx.mlx_window, 17, 0, &destroy, &cub3d->mlx);
	mlx_loop(cub3d->mlx.mlx);
}

void	initialize_map(t_cub3d *cub3d)
{
	int	map[24][24]= {
	{1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};

	cub3d->map_2d_array = malloc(sizeof(int *) * 24);
	for (int x = 0; x < 24; ++x)
	{
		cub3d->map_2d_array[x] = malloc(sizeof(int) * 24);
	}
	for (int i = 0; i < 24; ++i)
	{
		for (int k = 0; k < 24; ++k)
		{
			cub3d->map_2d_array[i][k] = map[i][k];
		}
	}
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
	cub3d->colour_ceiling = 0x000000FF;
	cub3d->colour_floor = 0x0000FF00;
	cub3d->colour_wall = 0x00FF0000;
	cub3d->colour_wall2 = cub3d->colour_wall / 2;

	cub3d->render_walls.ray_coordinate_in_camera_plane = 0;
	cub3d->render_walls.ray_direction_x = 0;
	cub3d->render_walls.ray_direction_y = 0;
	cub3d->render_walls.player_which_map_cell_x = 0;
	cub3d->render_walls.player_which_map_cell_y = 0;
	cub3d->render_walls.straight_wall_distance = 0;
	cub3d->render_walls.length_of_ray_to_next_x = 0;
	cub3d->render_walls.length_of_ray_to_next_y = 0;
	cub3d->render_walls.delta_distance_to_next_x = 0;
	cub3d->render_walls.delta_distance_to_next_y = 0;
	cub3d->render_walls.take_step_in_x = 0;
	cub3d->render_walls.take_step_in_y = 0;
	cub3d->render_walls.wall_hit = 0;
	cub3d->render_walls.which_side_hit = 0;
	cub3d->render_walls.wall_height = 0;
	cub3d->render_walls.draw_limit_low = 0;
	cub3d->render_walls.draw_limit_high = 0;

	cub3d->player_position_x = 22;
	cub3d->player_position_y = 12;
	cub3d->player_direction_x = -1;
	cub3d->player_direction_y = 0;
	cub3d->camera_plane_x = 0;
	cub3d->camera_plane_y = 0.66;
	cub3d->height_map = 24;
	cub3d->width_map = 24;

	cub3d->key_w_down = 0;
	cub3d->key_a_down = 0;
	cub3d->key_s_down = 0;
	cub3d->key_d_down = 0;
	cub3d->key_arrow_up_down = 0;
	cub3d->key_arrow_down_down = 0;
	cub3d->key_arrow_left_down = 0;
	cub3d->key_arrow_right_down = 0;

	initialize_map(cub3d);
	mlx_initialization(cub3d);

}
