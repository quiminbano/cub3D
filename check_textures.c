/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_celling.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:51:27 by corellan          #+#    #+#             */
/*   Updated: 2023/04/20 18:40:20 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_textures(char **array)
{
	int	no;
	int	so;
	int	ea;
	int	we;
	int	len;

	no = ft_find_word_array(array, "NO");
	so = ft_find_word_array(array, "SO");
	ea = ft_find_word_array(array, "EA");
	we = ft_find_word_array(array, "WE");
	len = ft_array_len(array);
	if (no == len || so == len || ea == len || we == len)
	{
		print_error(TEXTURES_MISSING);
		return (1);
	}
	else if (no > 5 || so > 5 || ea > 5 || we > 5)
	{
		print_error(WRONG_INPUT);
		return (1);
	}
	return (0);
}
