/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_floor_celling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:40:31 by corellan          #+#    #+#             */
/*   Updated: 2023/04/22 11:59:10 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	play_with_bits(int i, int flag, int *colour, char **array)
{
	if (flag == 1 || i > 3)
	{
		ft_free_split(array);
		print_error(WRONG_INPUT);
		return (1);
	}
	(*colour) = ((0 << 24) | (ft_atoi(array[0]) << 16) | \
		(ft_atoi(array[1]) << 8) | (ft_atoi(array[2])));
	ft_free_split(array);
	return (0);
}

static int	check_parameters(char **array, int *colour)
{
	int		i;
	int		flag;
	char	**temp;

	i = 0;
	flag = 0;
	temp = NULL;
	while (array != NULL && array[i] != NULL)
	{
		temp = ft_split(array[i], ' ');
		if ((temp == NULL) || (temp[1] != NULL) || \
			(check_is_number(temp[0]) == 1 || \
			check_valid_number(temp[0]) == 1))
		{
			ft_free_split(temp);
			flag = 1;
			break ;
		}
		i++;
		ft_free_split(temp);
	}
	return (play_with_bits(i, flag, &(*colour), array));
}

static int	check_floor_celling_aux(char **array, int c, int f, t_cub3d *img)
{
	char	**celling;
	char	**floor;

	celling = ft_split(array[c] + 1, ',');
	floor = ft_split(array[f] + 1, ',');
	if (celling == NULL || floor == NULL)
	{
		if (floor != NULL)
			ft_free_split(floor);
		if (celling != NULL)
			ft_free_split(celling);
		return (1);
	}
	if (check_parameters(celling, &(img->colour_celling)) == 1)
		return (1);
	if (check_parameters(floor, &(img->colour_floor)) == 1)
		return (1);
	return (0);
}

int	check_floor_celling(char **array, t_cub3d *img)
{
	int	c;
	int	f;
	int len;

	c = ft_find_word_array(array, "C");
	f = ft_find_word_array(array, "F");
	len = ft_array_len(array);
	if (c == len || f == len)
	{
		print_error(FLOOR_CELLING_MISSING);
		return (1);
	}
	else if (c > 5 || f > 5)
	{
		print_error(WRONG_INPUT);
		return (1);
	}
	return (check_floor_celling_aux(array, c, f, &(*img)));
}
