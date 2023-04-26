/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:15:47 by corellan          #+#    #+#             */
/*   Updated: 2023/04/26 10:21:47 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	longest_length(char **map)
{
	int	i;
	int	len_i;
	int	len;

	len = ft_strlen(map[0]);
	i = 0;
	while (map[i] != NULL)
	{
		len_i = ft_strlen(map[i]);
		if (len_i > len)
			len = len_i;
		i++;
	}
	return (len);
}
