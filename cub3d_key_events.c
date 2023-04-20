/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_key_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:19:59 by corellan          #+#    #+#             */
/*   Updated: 2023/04/18 20:02:09 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_down_event(int key_code, t_cub3d *cub3d)
{
	// For testing purpose
	printf("Key code: %d\n", key_code);

	if (key_code == KEY_ESC)
		destroy((cub3d));
	return (0);
}
