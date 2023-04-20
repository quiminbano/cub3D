/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_in_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:53:16 by tpoho             #+#    #+#             */
/*   Updated: 2023/04/20 13:56:25 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel_in_image(t_cub3d *cub3d, int x, int y, int colour)
{
	char	*pixel;

	if (x >= 0 && x < WIDTH_WINDOW && y >= 0 && y < HEIGHT_WINDOW)
	{
		if (cub3d->which_image == 0)
			pixel = cub3d->image_1.address;
		else
			pixel = cub3d->image_2.address;
		pixel = pixel + (y * cub3d->image_1.line_length
				+ (x * (cub3d->image_1.bits_per_pixel / 8)));
		*(unsigned int *) pixel = colour;
	}
}
