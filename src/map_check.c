/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:04:54 by vdenisse          #+#    #+#             */
/*   Updated: 2023/11/08 13:11:07 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_wall_check(t_map **map, int x, int y)
{
	int	i;

	i = 0;
	while (i < x)
		if (map[0][i++].tile->code != '1')
			return (INVALID_OUTER_WALL);
	i = 0;
	while (i < y)
		if (map[i++][0].tile->code != '1')
			return (INVALID_OUTER_WALL);
	i = 0;
	while (i < x)
		if (map[y - 1][i++].tile->code != '1')
			return (INVALID_OUTER_WALL);
	i = 0;
	while (i < y)
		if (map[i++][x - 1].tile->code != '1')
			return (INVALID_OUTER_WALL);
	return (1);
}

int	check_tile(char code, int last_call)
{
	static int	init;
	static int	start;
	static int	end;
	static int	coll;

	if (!init)
	{
		start = 0;
		end = 0;
		init = 1;
	}
	if (code != '1' && code != '0' && code != 'C' && code != 'P' && code != 'E')
		return (1);
	if (code == 'P')
		start++;
	if (code == 'E')
		end++;
	if (code == 'C')
		coll++;
	if (start > 1 || end > 1)
		return (1);
	if (last_call)
		if (coll < 1 || start != 1 || end != 1)
			return (1);
	return (0);
}

int	map_content_check(t_map **map, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
			if (check_tile(map[i][j++].tile->code, 0))
				return (INVALID_CONTENT);
		i++;
	}
	if (check_tile(map[0][0].tile->code, 1))
		return (INVALID_CONTENT);
	return (1);
}

t_map	**copy_map(t_data *data)
{
	t_map	**map_copy;
	int		i;

	i = 0;
	map_copy = malloc(data->max_y * sizeof(t_map *));
	while (i < data->max_y)
	{
		map_copy[i] = malloc(data->max_x * sizeof(t_map));
		ft_memcpy(map_copy[i], (data->map)[i], data->max_x * sizeof(t_map));
		++i;
	}
	return (map_copy);
}

int	map_check(int x, int y, t_data *data)
{
	t_map	**map_copy;
	int		err;

	map_copy = copy_map(data);
	err = 1;
	err *= map_wall_check(map_copy, x, y);
	err *= map_content_check(map_copy, x, y);
	if (err % INVALID_OUTER_WALL == 0)
	{
		free_map(data, map_copy);
		return (err);
	}
	err *= map_flood_check(map_copy, x, y, data->tiles);
	free_map(data, map_copy);
	return (err);
}
