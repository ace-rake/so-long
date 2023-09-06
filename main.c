/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:32:46 by vdenisse          #+#    #+#             */
/*   Updated: 2023/09/05 12:08:19 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

t_tile	*tile_constructor(char code, char *texture_path)
{
	t_tile	*tile;

	tile = (t_tile *)malloc(sizeof(t_tile));
	if (!tile)
		return (0);
	tile->code = code;
	tile->texture_path = ft_strjoin("./textures/", texture_path);
	return (tile);
}

t_tile_set	*player_set_constructor(char code)
{
	t_tile_set	*pts;

	pts = (t_tile_set *)malloc(sizeof(t_tile_set));
	pts->up = tile_constructor(code, "rat-up_128x128.xpm");
	pts->right = tile_constructor(code, "rat-right_128x128.xpm");
	pts->down = tile_constructor(code, "rat-down_128x128.xpm");
	pts->left = tile_constructor(code, "rat-left_128x128.xpm");
	return (pts);
}

t_tiles	*tiles_init(void)
{
	t_tiles	*tiles;

	tiles = (t_tiles *)malloc (sizeof (t_tiles));
	tiles->obstacle = tile_constructor('1', "wall_128x128.xpm");
	tiles->empty = tile_constructor('0', "1.xpm");
	tiles->collectible = tile_constructor('C', "cheese_128x128.xpm");
	tiles->player = player_set_constructor('R');
	tiles->start = tile_constructor('P', "missing-texture_128x128.xpm");
	tiles->end = tile_constructor('E', "missing-texture_128x128.xpm");
	tiles->flooded = tile_constructor('2', "cheese_128x128.xpm");
	return (tiles);
}

int	main(int argc, char *argv[])
{
	t_tiles	*tiles;
	t_data	*data;

	if (argc != 2)
		return (0);
	data = (t_data *)malloc(sizeof(t_data));
	tiles = tiles_init();
	data->tiles = tiles;
	data->map = NULL;
	if (argc >= 1)
	{
		if (map_parse(&data, argv[1], tiles))
		{
			printf("error\n");
			cleanup(data);
			return (1);
		}
	}
	master(data);
	cleanup(data);
	return (0);
}
