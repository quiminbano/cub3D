/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:59:41 by corellan          #+#    #+#             */
/*   Updated: 2023/04/19 16:34:57 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"
# define NO_INPUT 1
# define MANY_ARG 2
# define WRONG_FORMAT 3
# define INVALID_FILE 4

typedef struct s_cub3d
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_cub3d;

void	print_error(int error);
int		check_map(char **av);
int		check_argument(int ac, char **av);
int		destroy(t_cub3d *img);
int		keydownevent(int keycode, t_cub3d *img);

#endif