/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:59:51 by tpoho             #+#    #+#             */
/*   Updated: 2023/04/20 14:00:42 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_floor_ceiling(t_cub3d *cub3d)
{
	int	x;
	int	y;
	int	upper_half;

	upper_half = HEIGHT_WINDOW / 2;
	y = 0;
	while (y < upper_half)
	{
		x = 0;
		while (x < WIDTH_WINDOW)
		{
			put_pixel_in_image(cub3d, x, y, cub3d->colour_ceiling);
			put_pixel_in_image(cub3d, x, (y + upper_half), cub3d->colour_floor);
			++x;
		}
		++y;
	}
}
