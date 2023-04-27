/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:09:49 by tpoho             #+#    #+#             */
/*   Updated: 2023/04/27 15:34:16 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

---carlos
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
--timo
int	main(int argc, char **argv)
{
	t_cub3d	cub3d;

	initialization(argc, argv, &cub3d);
	return (0);
}
