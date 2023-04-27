/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:59:41 by corellan          #+#    #+#             */
/*   Updated: 2023/04/27 15:34:50 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <mlx.h>

# define WIDTH_WINDOW 800
# define HEIGHT_WINDOW 600
# define HEIGHT_WINDOW_HALF 300

# define PI 3.141592653589793238462643383279
# define TWO_TIMES_PI 6.283185307179586476925286766559

# define IN_THE_MIDDLE_OF_SQUARE 0.5
# define EMPTY_SQUARE 0
# define WALL_SQUARE 1

# define MOVEMENT_SPEED 0.04
# define TURNING_SPEED 0.02

# define KEY_ESC 53
# define PLAYER_COLLISION_DISTANCE 0.01 

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_window;
}			t_mlx;

typedef struct s_image
{
	void	*image;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endianness;
}			t_image;

typedef struct s_render_walls
{
	double	ray_coordinate_in_camera_plane;
	double	ray_direction_x;
	double	ray_direction_y;
	int		player_which_map_cell_x;
	int		player_which_map_cell_y;
	double	straight_wall_distance;
	double	length_of_ray_to_next_x;
	double	length_of_ray_to_next_y;
	double	delta_distance_to_next_x;
	double	delta_distance_to_next_y;
	int		take_step_in_x;
	int		take_step_in_y;
	int		wall_hit;
	int		which_side_hit;
	int		wall_height;
	int		wall_height_half;
	int		draw_limit_low;
	int		draw_limit_high;
}			t_render_walls;

typedef struct s_cub3d
{
	t_mlx			mlx;
	t_image			image_1;
	t_image			image_2;
	t_render_walls	render_walls;
	int				which_image;
	int				colour_ceiling;
	int				colour_floor;
	int				colour_wall;
	int				colour_wall2;
	double			player_position_x;
	double			player_position_y;
	double			player_direction_x;
	double			player_direction_y;
	double			camera_plane_x;
	double			camera_plane_y;
	char			**map_2d_array;
	int				width_map;
	int				height_map;
	int				put_pixel_in_image_temp;
	int				key_w_down;
	int				key_a_down;
	int				key_s_down;
	int				key_d_down;
	int				key_arrow_up_down;
	int				key_arrow_down_down;
	int				key_arrow_left_down;
	int				key_arrow_right_down;	
}			t_cub3d;

void	initialization(int argc, char **argv, t_cub3d *cub3d);
int		destroy(t_cub3d *cub3d);

int		key_down_event(int keycode, t_cub3d *variables);
int		key_up_event(int key_code, t_cub3d *cub3d);

void	put_pixel_in_image(t_cub3d *cub3d, int x, int y, int colour);

int		game_loop(t_cub3d *cub3d);
void	render_floor_ceiling(t_cub3d *cub3d);
void	render_walls(t_cub3d *cub3d);
void	draw_window(t_cub3d *cub3d, int x_coord);

void	in_which_box_we_are_in_map(t_cub3d *cub3d);
void	compute_ray_position_and_direction(t_cub3d *cub3d, int x_coord);
void	compute_delta_distances(t_cub3d *cub3d);
void	compute_x_step_and_initial_length_to_next_x(t_cub3d *cub3d);
void	compute_y_step_and_initial_length_to_next_y(t_cub3d *cub3d);
void	compute_ray_distance_with_dda(t_cub3d *cub3d);

void	move_forward(t_cub3d *cub3d);
void	move_backward(t_cub3d *cub3d);

void	turn_right(t_cub3d *cub3d);
void	turn_left(t_cub3d *cub3d);

void	strafe_left(t_cub3d *cub3d);
void	strafe_right(t_cub3d *cub3d);

#endif
