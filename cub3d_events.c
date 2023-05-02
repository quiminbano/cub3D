/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:13:19 by corellan          #+#    #+#             */
/*   Updated: 2023/05/02 18:19:33 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	destroy(t_cub3d *cub3d)
{
	mlx_destroy_image(cub3d->mlx.mlx, cub3d->ptr_no);
	mlx_destroy_image(cub3d->mlx.mlx, cub3d->ptr_so);
	mlx_destroy_image(cub3d->mlx.mlx, cub3d->ptr_ea);
	mlx_destroy_image(cub3d->mlx.mlx, cub3d->ptr_we);
	mlx_destroy_image(cub3d->mlx.mlx, cub3d->image_1.image);
	mlx_destroy_image(cub3d->mlx.mlx, cub3d->image_2.image);
	mlx_destroy_window(cub3d->mlx.mlx, cub3d->mlx.mlx_window);
	ft_free_int(cub3d->map_int, cub3d->height_map);
	cub3d->mlx.mlx = NULL;
	cub3d->mlx.mlx_window = NULL;
	exit(0);
}
