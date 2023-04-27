/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:37:35 by tpoho             #+#    #+#             */
/*   Updated: 2023/04/27 13:39:34 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cub3d	cub3d;

	if (check_argument(ac, av) == 1)
		exit (EXIT_FAILURE);
	if (check_file_map(av, &(cub3d)) == 1)
		exit (EXIT_FAILURE);
	cub3d.mlx = mlx_init();
	cub3d.mlx_win = mlx_new_window(cub3d.mlx, 800, 600, "cub3D");
	if (check_textures(cub3d.file, &cub3d) == 1)
	{
		if (cub3d.ptr_no != NULL)
			mlx_destroy_image(cub3d.mlx, cub3d.ptr_no);
		if (cub3d.ptr_so != NULL)
			mlx_destroy_image(cub3d.mlx, cub3d.ptr_so);
		if (cub3d.ptr_ea != NULL)
			mlx_destroy_image(cub3d.mlx, cub3d.ptr_ea);
		if (cub3d.ptr_we != NULL)
			mlx_destroy_image(cub3d.mlx, cub3d.ptr_we);
		exit (EXIT_FAILURE);
	}
	mlx_hook(cub3d.mlx_win, 2, 0, &keydownevent, &(cub3d));
	mlx_hook(cub3d.mlx_win, 17, 0, &destroy, &(cub3d));
	mlx_loop(cub3d.mlx);
	return (0);
}
