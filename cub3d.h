/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:59:41 by corellan          #+#    #+#             */
/*   Updated: 2023/04/20 17:41:56 by corellan         ###   ########.fr       */
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
# define TEXTURES_MISSING 5
# define WRONG_INPUT 6
# define FLOOR_CELLING_MISSING 7

typedef struct s_cub3d
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		colour_celling;
	int		colour_floor;
}			t_cub3d;

void	print_error(int error);
int		check_map(char **av, t_cub3d *img);
int		check_textures(char **array);
int		check_argument(int ac, char **av);
int		check_floor_celling(char **array, t_cub3d *img);
int		check_valid_number(char const *str);
int		check_is_number(char *str);
int		ft_find_word_array(char **array, char *needle);
int		ft_array_len(char **array);
int		ft_count_space(char *str);
int		destroy(t_cub3d *img);
int		keydownevent(int keycode, t_cub3d *img);

#endif