/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:59:41 by corellan          #+#    #+#             */
/*   Updated: 2023/04/27 14:36:33 by corellan         ###   ########.fr       */
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
# define TEXTURE_NOT_FOUND 8
# define NO_MAP 9
# define INVALID_MAP 10

typedef struct s_cub3d
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		fd;
	char	***av_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		idx_no;
	int		idx_so;
	int		idx_we;
	int		idx_ea;
	int		colour_celling;
	int		colour_floor;
	char	*no_path;
	char	*so_path;
	char	*ea_path;
	char	*we_path;
	void	*ptr_no;
	void	*ptr_so;
	void	*ptr_ea;
	void	*ptr_we;
	char	**file;
	char	**map;
}			t_cub3d;

typedef struct s_coord
{
	int	row;
	int	col;
	int	i_row;
	int	j_col;
	int	i;
	int	j;
}				t_coord;

void	print_error(int error);
int		check_file_map(char **av, t_cub3d *cub3d);
int		check_presence_textures(char **array, t_cub3d *cub3d);
int		check_argument(int ac, char **av);
int		check_floor_celling(char **array, t_cub3d *img);
int		check_valid_number(char const *str);
int		check_is_number(char *str);
int		check_map(char **map, t_cub3d *cub3d);
int		check_mases(char **map, int flag);
int		check_empty_lines(char **map, t_cub3d *cub3d);
int		ft_find_word_array(char **array, char *needle);
int		ft_array_len(char **array);
int		ft_count_space(char *str);
int		check_textures(char **file, t_cub3d *cub3d);
int		destroy(t_cub3d *img);
int		keydownevent(int keycode, t_cub3d *img);
int		longest_length(char **map);
int		error_free(char **array, int i);
int		check_after_flood_fill(char ***map);

#endif