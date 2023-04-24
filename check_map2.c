/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:18:43 by corellan          #+#    #+#             */
/*   Updated: 2023/04/24 18:51:57 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	analize_line(char **map, int i)
{
	int	len;
	int	j;
	int	len_w_s;
	int	sp_c_next;

	len = ft_strlen(map[i + 1]);
	j = 0;
	len_w_s = 0;
	sp_c_next = 0;
	while (map[i][j] != '\0')
	{
		if (map[i][j] == ' ')
			len_w_s = 0;
		else
		{
			if ((j >= len) || (map[i + 1][j] == ' '))
				sp_c_next++;
			len_w_s++;
		}
		j++;
	}
	if (sp_c_next >= len_w_s)
		return (1);
	return (0);
}

int	check_mases(char **map)
{
	int	i;
	int	len_map;

	i = 0;
	len_map = ft_array_len(map);
	while (i < (len_map - 1))
	{
		if (analize_line(map, i) == 1)
			break ;
		i++;
	}
	if (i < (len_map - 1))
	{
		print_error(INVALID_MAP);
		return (1);
	}
	return (0);
}
