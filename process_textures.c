/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:07:39 by corellan          #+#    #+#             */
/*   Updated: 2023/05/04 16:54:06 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	fill_array(t_cub3d *cub3d, int width, int heigth, int i)
{
	int		x;
	int		y;
	char	*pixel;

	x = 0;
	y = 0;
	cub3d->textures[i] = malloc(sizeof(int) * (width * heigth));
	if (!cub3d->textures[i])
		return (1);
	while (y < heigth)
	{
		x = 0;
		while (x < width)
		{
			if (i == 0)
				pixel = cub3d->no_tex.address + (y * cub3d->no_tex.line_length
					+ (x * (cub3d->no_tex.bits_per_pixel / 8)));
			if (i == 1)
				pixel = cub3d->so_tex.address + (y * cub3d->so_tex.line_length
					+ (x * (cub3d->so_tex.bits_per_pixel / 8)));
			if (i == 2)
				pixel = cub3d->we_tex.address + (y * cub3d->we_tex.line_length
					+ (x * (cub3d->we_tex.bits_per_pixel / 8)));
			if (i == 3)
				pixel = cub3d->ea_tex.address + (y * cub3d->ea_tex.line_length
					+ (x * (cub3d->ea_tex.bits_per_pixel / 8)));
			cub3d->textures[i][x + (y * width)] = *(unsigned int *)pixel;
			x++;
		}
		y++;
	}
	return (0);
}

void	create_int_array_textures(t_cub3d *cub3d)
{
	cub3d->textures = malloc(sizeof(int *) * 4);
	if (!cub3d->textures)
		return ;
	if (fill_array(cub3d, cub3d->no_tex.width_tex, cub3d->no_tex.height_tex, 0) || \
		fill_array(cub3d, cub3d->so_tex.width_tex, cub3d->so_tex.height_tex, 1) || \
		fill_array(cub3d, cub3d->we_tex.width_tex, cub3d->we_tex.height_tex, 2) || \
		fill_array(cub3d, cub3d->ea_tex.width_tex, cub3d->ea_tex.height_tex, 3))
	{
		free(cub3d->textures);
		destroy(cub3d);
	}
}
