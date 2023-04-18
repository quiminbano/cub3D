/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:37:35 by tpoho             #+#    #+#             */
/*   Updated: 2023/04/18 11:25:48 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(void)
{
	t_cub3d	img;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 800, 600, "cub3D");
	mlx_hook(img.mlx_win, 2, 0, &keydownevent, &img);
	mlx_hook(img.mlx_win, 17, 0, &destroy, &img);
	mlx_loop(img.mlx);
	return (0);
}
