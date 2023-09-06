/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:30:12 by vdenisse          #+#    #+#             */
/*   Updated: 2023/09/05 12:08:52 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

int	collectible_count(t_data *data, t_map **map)
{
	int	count;
	int	iter;
	int	jter;

	count = 0;
	iter = 0;
	while (iter < data->max_y)
	{
		jter = 0;
		while (jter < data->max_x)
		{
			if (map[iter][jter].tile == data->tiles->collectible)
				count++;
			jter++;
		}
		iter++;
	}
	return (count);
}

int	master(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1920, 1024, "so_long");
	data->img = NULL;
	data->width = 1920;
	data->height = 1024;
	data->texture_size = 128;
	data->game_info.step_count = 0;
	create_images(data);
	data->game_info.total_collectibles = collectible_count(data, data->map);
	data->game_info.collectibles_collected = 0;
	data->game_info.stand_on_tile = data->tiles->start;
	game_start(&data);
	return (0);
}

void	place_player(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	finder(data, &y, &x, data->tiles->start->code);
	data->map[y][x].tile = data->tiles->player->down;
}

int	game_start(t_data **data_src)
{
	t_data		*data;
	t_map_seg	**map_seg;

	data = *data_src;
	place_player(data);
	map_seg = get_map_segment(data, 1);
	data->map_seg = map_seg;
	print_map_seg(map_seg, 8, 15);
	update_screen(data_src, 0);
	mlx_key_hook(data->win, key_handle_game, data_src);
	mlx_hook(data->win, 17, 0, click_close, &data);
	mlx_loop(data->mlx);
	return (0);
}
