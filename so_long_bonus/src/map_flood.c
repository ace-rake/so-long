/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:22:44 by vdenisse          #+#    #+#             */
/*   Updated: 2023/11/06 11:38:39 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	can_flood(t_map ***map_src, int x, int y, t_tiles *tiles)
{
	t_map	**map;

	map = *map_src;
	if (map[y][x].tile->code == '1' || map[y][x].tile->code == '2')
		return (0);
	if (map[y + 1][x].tile->code == '2' ||
		map[y - 1][x].tile->code == '2' ||
		map[y][x + 1].tile->code == '2' ||
		map[y][x - 1].tile->code == '2')
	{
		map[y][x].tile = tiles->flooded;
		return (1);
	}
	return (0);
}

int	flood(t_map **map, int x, int y, t_tiles *tiles)
{
	int	has_flooded;
	int	i;
	int	j;

	has_flooded = 0;
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (i != y && j != x && i != 0 && j != 0)
				if (can_flood(&map, j, i, tiles))
					has_flooded++;
			j++;
		}
		i++;
	}
	return (has_flooded);
}

void	flood_start(t_map ***map, int x, int y, t_tiles *tiles)
{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if ((*map)[i][j].tile->code == 'P')
			{
				(*map)[i][j].tile = tiles->flooded;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	post_flood_check(t_map **map, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < y)
	{
		j = -1;
		while (++j < x)
			if (map[i][j].tile->code == 'P' || map[i][j].tile->code == 'E'
				|| map[i][j].tile->code == 'C')
				return (1);
	}
	return (0);
}

int	map_flood_check(t_map **map, int x, int y, t_tiles *tiles)
{
	int	i;

	i = 0;
	flood_start(&map, x, y, tiles);
	while (flood(map, x, y, tiles))
	{
		i++;
	}
	if (post_flood_check(map, x, y))
		return (1);
	return (0);
}
