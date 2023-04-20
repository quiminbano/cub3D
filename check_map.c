/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:25:40 by corellan          #+#    #+#             */
/*   Updated: 2023/04/20 18:11:08 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**process_array_aux(char ***temp, char ***array, int i, int j)
{
	while ((*array)[i] != NULL)
	{
		if (ft_count_space((*array)[i]) != (int)ft_strlen((*array)[i]))
		{
			(*temp)[j] = ft_strdup((*array)[i]);
			j++;
		}
		i++;
	}
	ft_free_split((*array));
	return ((*temp));
}

static char	**process_array(char ***array)
{
	int		i;
	int		j;
	char	**temp;

	i = 0;
	j = 0;
	while ((*array)[i] != NULL)
	{
		if (ft_count_space((*array)[i]) != (int)ft_strlen((*array)[i]))
			j++;
		i++;
	}
	temp = (char **)malloc(sizeof(char *) * (j + 1));
	if (temp == NULL)
	{
		ft_free_split((*array));
		return (NULL);
	}
	temp[j] = NULL;
	i = 0;
	j = 0;
	return (process_array_aux(&temp, &(*array), i, j));
}

static int	check_map_aux(char **doc, t_cub3d *img)
{
	char	**array;

	array = NULL;
	array = ft_split((*doc), '\n');
	array = process_array(&array);
	free(*doc);
	if (check_textures(array) == 1 || check_floor_celling(array, &(*img)) == 1)
	{
		ft_free_split(array);
		return (1);
	}
	ft_free_split(array);
	return (0);
}

int	check_map(char **av, t_cub3d *img)
{
	int		fd;
	char	*str;
	char	*doc;
	int		flag;

	fd = open(av[1], O_RDONLY);
	flag = 0;
	if (fd == -1)
	{
		print_error(INVALID_FILE);
		return (1);
	}
	str = ft_calloc(1, 1);
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		if (flag == 0)
			doc = ft_strdup("");
		if (str != NULL)
			doc = ft_strjoin_free(doc, str);
		flag = 1;
	}
	close(fd);
	return (check_map_aux(&doc, &(*img)));
}