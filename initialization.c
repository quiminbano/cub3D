/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:55:11 by tpoho             #+#    #+#             */
/*   Updated: 2023/04/28 13:57:56 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	mlx_initialization(t_cub3d *cub3d)
{
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

static void map_initialization(int ac, char **av, t_cub3d *cub3d)
{
	if (check_argument(ac, av) == 1)
		exit (EXIT_FAILURE);
	if (check_file_map(av, cub3d) == 1)
		exit (EXIT_FAILURE);
	cub3d->mlx.mlx = mlx_init();
	cub3d->mlx.mlx_window = mlx_new_window(cub3d->mlx.mlx,
			WIDTH_WINDOW, HEIGHT_WINDOW, "cub3D");
	if (check_textures(cub3d->file, &(*cub3d)) == 1)
	{
		if (cub3d->ptr_no != NULL)
			mlx_destroy_image(cub3d->mlx.mlx, cub3d->ptr_no);
		if (cub3d->ptr_so != NULL)
			mlx_destroy_image(cub3d->mlx.mlx, cub3d->ptr_so);
		if (cub3d->ptr_ea != NULL)
			mlx_destroy_image(cub3d->mlx.mlx, cub3d->ptr_ea);
		if (cub3d->ptr_we != NULL)
			mlx_destroy_image(cub3d->mlx.mlx, cub3d->ptr_we);
		exit (EXIT_FAILURE);
	}
	create_int_map(cub3d);
}

void	initialization(int argc, char **argv, t_cub3d *cub3d)
{
	map_initialization(argc, argv, &(*cub3d));
	cub3d->which_image = 0;
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
	//cub3d->player_position_x = 2.5;
	//cub3d->player_position_y = 2.5;
	//cub3d->player_direction_x = 0;
	//cub3d->player_direction_y = 1;
	cub3d->camera_plane_x = 0;
	cub3d->camera_plane_y = 0.66;
	//cub3d->height_map = 24;
	//cub3d->width_map = 24;
	cub3d->key_w_down = 0;
	cub3d->key_a_down = 0;
	cub3d->key_s_down = 0;
	cub3d->key_d_down = 0;
	cub3d->key_arrow_up_down = 0;
	cub3d->key_arrow_down_down = 0;
	cub3d->key_arrow_left_down = 0;
	cub3d->key_arrow_right_down = 0;
	mlx_initialization(cub3d);
}
