/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:04:00 by corellan          #+#    #+#             */
/*   Updated: 2023/04/26 19:50:08 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_after_flood_fill(char ***map)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while ((*map)[i] != NULL)
	{
		j = 0;
		while ((*map)[i][j] != '\0')
		{
			if (((*map)[i][j] != ' ') && ((*map)[i][j] != '3'))
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 1)
			break ;
		i++;
	}
	if (flag == 1)
		return (1);
	return (0);
}
