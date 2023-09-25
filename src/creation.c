/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:16:08 by vdenisse          #+#    #+#             */
/*   Updated: 2023/09/25 11:17:53 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	create_image(t_data *data, t_tile *tile)
{
	tile->img = mlx_xpm_file_to_image(data->mlx, tile->texture_path,
			&data->texture_size, &data->texture_size);
}

void	create_images(t_data *data)
{
	t_tiles	*tiles;

	tiles = data->tiles;
	create_image(data, tiles->obstacle);
	create_image(data, tiles->empty);
	create_image(data, tiles->collectible);
	create_image(data, tiles->player->up);
	create_image(data, tiles->player->right);
	create_image(data, tiles->player->down);
	create_image(data, tiles->player->left);
	create_image(data, tiles->start);
	create_image(data, tiles->end);
	create_image(data, tiles->flooded);
}
