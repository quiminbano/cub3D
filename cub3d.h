/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:59:41 by corellan          #+#    #+#             */
/*   Updated: 2023/04/20 14:11:49 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include<stdio.h>
# include <mlx.h>
# include "libft/libft.h"

# define WIDTH_WINDOW 800
# define HEIGHT_WINDOW 600

# define KEY_ESC 53

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

typedef struct s_cub3d
{
	t_mlx	mlx;
	t_image	image_1;
	t_image	image_2;
	int		which_image;
	int		colour_ceiling;
	int		colour_floor;
}			t_cub3d;	

int		destroy(t_cub3d *cub3d);
int		key_down_event(int keycode, t_cub3d *variables);
void	put_pixel_in_image(t_cub3d *cub3d, int x, int y, int colour);
void	initialization(int argc, char **argv, t_cub3d *cub3d);
int		game_loop(t_cub3d *cub3d);
void	render_floor_ceiling(t_cub3d *cub3d);

#endif
