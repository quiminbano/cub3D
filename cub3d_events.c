/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:13:19 by corellan          #+#    #+#             */
/*   Updated: 2023/04/22 11:15:43 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	destroy(t_cub3d *img)
{
	mlx_destroy_image(img->mlx, img->ptr_no);
	mlx_destroy_image(img->mlx, img->ptr_so);
	mlx_destroy_image(img->mlx, img->ptr_ea);
	mlx_destroy_image(img->mlx, img->ptr_we);
	mlx_destroy_window(img->mlx, img->mlx_win);
	img->mlx = NULL;
	img->mlx_win = NULL;
	exit(0);
}
