/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:13:19 by corellan          #+#    #+#             */
/*   Updated: 2023/04/18 20:02:11 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	destroy(t_cub3d *cub3d)
{
	mlx_destroy_window(cub3d->mlx.mlx, cub3d->mlx.mlx_window);
	cub3d->mlx.mlx = NULL;
	cub3d->mlx.mlx_window = NULL;
	exit(0);
}
