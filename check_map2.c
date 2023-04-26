/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:18:43 by corellan          #+#    #+#             */
/*   Updated: 2023/04/26 19:45:18 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	flood_fill(char ***temp, t_coord *id, int ro, int co)
{
	if (ro >= id->row || co >= id->col)
		return ;
	if (ro < 0 || co < 0)
		return ;
	if ((*temp)[ro][co] == ' ' || (*temp)[ro][co] == '\0')
		return ;
	if ((*temp)[ro][co] == 'N' || (*temp)[ro][co] == 'S' || \
		(*temp)[ro][co] == 'E' || (*temp)[ro][co] == 'W' || \
		(*temp)[ro][co] == '1' || (*temp)[ro][co] == '0')
	{
		(*temp)[ro][co] = '3';
		flood_fill(&(*temp), &(*id), (ro - 1), co);
		flood_fill(&(*temp), &(*id), (ro + 1), co);
		flood_fill(&(*temp), &(*id), ro, (co - 1));
		flood_fill(&(*temp), &(*id), ro, (co + 1));
	}
}

static int	find_player(char ***temp, t_coord *id)
{
	id->j = 0;
	while ((*temp)[id->i][id->j] != '\0')
	{
		if ((*temp)[id->i][id->j] == 'N' || (*temp)[id->i][id->j] == 'S' || \
			(*temp)[id->i][id->j] == 'E' || (*temp)[id->i][id->j] == 'W')
		{
			id->i_row = id->i;
			id->j_col = id->j;
			return (1);
		}
		(id->j)++;
	}
	return (0);
}

static int	find_start(char ***temp, int rows, int cols)
{
	t_coord	idx;

	idx.col = cols;
	idx.row = rows;
	idx.i_row = 0;
	idx.j_col = 0;
	idx.i = 0;
	while ((*temp)[idx.i] != NULL)
	{
		if (find_player(&(*temp), &idx) == 1)
			break ;
		(idx.i)++;
	}
	flood_fill(&(*temp), &idx, idx.i_row, idx.j_col);
	if (check_after_flood_fill(&(*temp)) == 1)
	{
		print_error(INVALID_MAP);
		ft_free_split((*temp));
		return (1);
	}
	ft_free_split((*temp));
	return (0);
}

static int	copy_rectangle(char ***temp, char **map, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < rows)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			(*temp)[i][j] = map[i][j];
			j++;
		}
		while (j < cols)
		{
			(*temp)[i][j] = ' ';
			j++;
		}
		(*temp)[i][j] = '\0';
		i++;
	}
	return (find_start(&(*temp), rows, cols));
}

int	check_mases(char **map, int flag)
{
	char	**temp;
	int		n_row;
	int		n_col;
	int		i;

	if (flag == 0)
	{
		print_error(INVALID_MAP);
		return (1);
	}
	n_row = ft_array_len(map);
	i = 0;
	n_col = longest_length(map);
	temp = (char **)malloc(sizeof(char *) * (n_row + 1));
	if (temp == NULL)
		return (1);
	temp[n_row] = NULL;
	while (i < n_row)
	{
		temp[i] = (char *)malloc(sizeof(char) * (n_col + 1));
		if (temp[i] == NULL)
			return (error_free(temp, i));
		i++;
	}
	return (copy_rectangle(&temp, map, n_row, n_col));
}
