/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:30:12 by vdenisse          #+#    #+#             */
/*   Updated: 2023/10/30 11:00:16 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	data->width = WINDOW_WIDTH;
	data->height = WINDOW_HEIGHT;
	data->texture_size = TEXTURE_INT;
	data->win = mlx_new_window(data->mlx, data->width, data->height, "so_long");
	data->img = NULL;
	data->game_info.step_count = 0;
	if (create_images(data))
		return (IMAGE_CREATION_ERR);
	data->game_info.total_collectibles = collectible_count(data, data->map);
	data->game_info.collectibles_collected = 0;
	data->game_info.stand_on_tile = data->tiles->empty;
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
	update_screen(data_src);
	mlx_key_hook(data->win, key_handle_game, data_src);
	mlx_hook(data->win, 17, 0, click_close, &data);
	mlx_loop(data->mlx);
	return (0);
}
