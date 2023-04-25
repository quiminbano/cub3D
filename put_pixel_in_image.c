/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_in_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:53:16 by tpoho             #+#    #+#             */
/*   Updated: 2023/04/25 20:12:18 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel_in_image(t_cub3d *cub3d, int x, int y, int colour)
{
	char	*pixel;

	if (cub3d->which_image == 0)
		pixel = cub3d->image_1.address;
	else
		pixel = cub3d->image_2.address;
	//if (x >= 0 && x < WIDTH_WINDOW && y >= 0 && y < HEIGHT_WINDOW)
	//{
		pixel = pixel + (y * cub3d->image_1.line_length
				+ (x * (cub3d->put_pixel_in_image_temp)));
		*(unsigned int *) pixel = colour;
	//}
}

void	put_pixel_in_image_2(t_cub3d *cub3d, int x, int y, int y2, int colour)
{
	char	*pixel;

	if (cub3d->which_image == 0)
		pixel = cub3d->image_1.address + (x * (cub3d->put_pixel_in_image_temp)) + (y * cub3d->image_1.line_length);
	else
		pixel = cub3d->image_2.address + (x * (cub3d->put_pixel_in_image_temp)) + (y * cub3d->image_1.line_length);
	//if (x >= 0 && x < WIDTH_WINDOW && y >= 0 && y < HEIGHT_WINDOW)
	//{
	*(unsigned int *) pixel = colour;
	++y;
		
	while (y <= y2)
	{
		pixel += cub3d->image_1.line_length;
		*(unsigned int *) pixel = colour;
		++y;
	}
	//}
}
