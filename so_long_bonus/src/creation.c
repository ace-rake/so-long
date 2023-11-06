/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:16:08 by vdenisse          #+#    #+#             */
/*   Updated: 2023/10/23 15:51:16 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_tile	*tile_constructor(char code, char *texture_path)
{
	t_tile	*tile;

	tile = (t_tile *)malloc(sizeof(t_tile));
	if (!tile)
		return (0);
	tile->code = code;
	tile->texture_path = ft_strjoin("./textures/", texture_path);
	return (tile);
}

static t_tile_set	*player_set_constructor(char code, char *name)
{
	t_tile_set	*pts;

	pts = (t_tile_set *)malloc(sizeof(t_tile_set));
	pts->up = tile_constructor(code, PLAYER "-up_" TEXTURE_SIZE EXTENSION);
	pts->right = tile_constructor(code, "rat-right_128x128.xpm");
	pts->down = tile_constructor(code, "rat-down_128x128.xpm");
	pts->left = tile_constructor(code, "rat-left_128x128.xpm");
	(void)name;
	return (pts);
}

t_tiles	*tiles_init(void)
{
	t_tiles	*tiles;

	tiles = (t_tiles *)malloc(sizeof(t_tiles));
	tiles->obstacle = tile_constructor('1', "wall_128x128.xpm");
	tiles->empty = tile_constructor('0', "1.xpm");
	tiles->collectible = tile_constructor('C', "cheese_better_128x128.xpm");
	tiles->player = player_set_constructor('R', "rat");
	tiles->start = tile_constructor('P', "sewer_no_rat_128x128.xpm");
	tiles->end = tile_constructor('E', "sewer_no_rat_128x128.xpm");
	tiles->flooded = tile_constructor('2', "toxic_waste_128x128.xpm");
	tiles->full = tile_constructor(0, "sewer_rat_128x128.xpm");
	return (tiles);
}

static int	create_image(t_data *data, t_tile *tile)
{
	tile->img = mlx_xpm_file_to_image(data->mlx, tile->texture_path,
			&data->texture_size, &data->texture_size);
	if (tile->img == NULL)
		return (1);
	return (0);
}

int	create_images(t_data *data)
{
	t_tiles	*tiles;

	tiles = data->tiles;
	if (create_image(data, tiles->obstacle))
		return (1);
	if (create_image(data, tiles->empty))
		return (1);
	if (create_image(data, tiles->collectible))
		return (1);
	if (create_image(data, tiles->player->up))
		return (1);
	if (create_image(data, tiles->player->right))
		return (1);
	if (create_image(data, tiles->player->down))
		return (1);
	if (create_image(data, tiles->player->left))
		return (1);
	if (create_image(data, tiles->start))
		return (1);
	if (create_image(data, tiles->end))
		return (1);
	if (create_image(data, tiles->full))
		return (1);
	return (create_image(data, tiles->flooded));
}
