/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:55:11 by tpoho             #+#    #+#             */
/*   Updated: 2023/05/04 15:39:57 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_addr_textures (t_cub3d *cub3d)
{
	cub3d->no_tex.address = mlx_get_data_addr(cub3d->no_tex.image,
			&cub3d->no_tex.bits_per_pixel, &cub3d->no_tex.line_length,
			&cub3d->no_tex.endianness);
	cub3d->so_tex.address = mlx_get_data_addr(cub3d->so_tex.image,
			&cub3d->so_tex.bits_per_pixel, &cub3d->so_tex.line_length,
			&cub3d->so_tex.endianness);
	cub3d->ea_tex.address = mlx_get_data_addr(cub3d->ea_tex.image,
			&cub3d->ea_tex.bits_per_pixel, &cub3d->ea_tex.line_length,
			&cub3d->ea_tex.endianness);
	cub3d->we_tex.address = mlx_get_data_addr(cub3d->we_tex.image,
			&cub3d->we_tex.bits_per_pixel, &cub3d->we_tex.line_length,
			&cub3d->we_tex.endianness);
}

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
	get_addr_textures(cub3d);
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
		if (cub3d->no_tex.image != NULL)
			mlx_destroy_image(cub3d->mlx.mlx, cub3d->no_tex.image);
		if (cub3d->so_tex.image != NULL)
			mlx_destroy_image(cub3d->mlx.mlx, cub3d->so_tex.image);
		if (cub3d->ea_tex.image != NULL)
			mlx_destroy_image(cub3d->mlx.mlx, cub3d->ea_tex.image);
		if (cub3d->we_tex.image != NULL)
			mlx_destroy_image(cub3d->mlx.mlx, cub3d->we_tex.image);
		exit (EXIT_FAILURE);
	}
	create_int_map(cub3d);
	ft_free_split(cub3d->file);
	ft_free_split(cub3d->map);
}

void	initial_orientation(t_cub3d *cub3d)
{
	double	temp_direction_x;
	double	temp_camera_plane_x;

	temp_direction_x = cub3d->player_direction_x;
	cub3d->player_direction_x = cub3d->player_direction_x * cos(cub3d->starting_angle)
		- cub3d->player_direction_y * sin(cub3d->starting_angle);
	cub3d->player_direction_y = temp_direction_x * sin(cub3d->starting_angle)
		+ cub3d->player_direction_y * cos(cub3d->starting_angle);
	temp_camera_plane_x = cub3d->camera_plane_x;
	cub3d->camera_plane_x = cub3d->camera_plane_x * cos(cub3d->starting_angle)
		- cub3d->camera_plane_y * sin(cub3d->starting_angle);
	cub3d->camera_plane_y = temp_camera_plane_x * sin(cub3d->starting_angle)
		+ cub3d->camera_plane_y * cos(cub3d->starting_angle);
}

void	create_textures(t_cub3d *cub3d)
{
	int	xorcolor;
	int	ycolor;
	int xycolor;

	cub3d->texture_width = 64;
	cub3d->texture_height = 64;
	
	for(int x = 0; x < cub3d->texture_width; x++)
  	{
		for(int y = 0; y < cub3d->texture_height; y++)
 	 	{
			xorcolor = (x * 256 / cub3d->texture_width) ^ (y * 256 / cub3d->texture_height);
    		//int xcolor = x * 256 / texWidth;
    		ycolor = y * 256 / cub3d->texture_height;
			xycolor = y * 128 / cub3d->texture_height + x * 128 / cub3d->texture_width;
			cub3d->textures[0][cub3d->texture_width * y + x] = 65536 * 254 * (x != y && x != cub3d->texture_width - y); //flat tex black cross
			cub3d->textures[1][cub3d->texture_width * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
			cub3d->textures[2][cub3d->texture_width * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
			cub3d->textures[3][cub3d->texture_width * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
		}
	}
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
	cub3d->camera_plane_x = 0;
	cub3d->camera_plane_y = 0.66;
	cub3d->key_w_down = 0;
	cub3d->key_a_down = 0;
	cub3d->key_s_down = 0;
	cub3d->key_d_down = 0;
	cub3d->key_arrow_up_down = 0;
	cub3d->key_arrow_down_down = 0;
	cub3d->key_arrow_left_down = 0;
	cub3d->key_arrow_right_down = 0;
	initial_orientation(cub3d);
	create_textures(cub3d);
	mlx_initialization(cub3d);
}
