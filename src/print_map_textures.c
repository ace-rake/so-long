/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:30:16 by vdenisse          #+#    #+#             */
/*   Updated: 2023/10/23 15:52:09 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"



int	update_screen(t_data **data_src)
{
	int		y;
	int		x;
	t_data	*data;

	data = *data_src;
	y = 0;
	while (y < 8)
	{
		x = 0;
		while (x < 15)
		{
			if (data->map_seg[y][x].oob != 1)
			{
			if (data->game_info.stand_on_tile == data->tiles->end && data->map_seg[y][x].map_src->tile->code == data->tiles->player->up->code)
				mlx_put_image_to_window(data->mlx, data->win,
					data->tiles->full->img, x * data->texture_size, y * data->texture_size);
			else if (data->game_info.stand_on_tile == data->tiles->start && data->map_seg[y][x].map_src->tile->code == data->tiles->player->up->code)
				mlx_put_image_to_window(data->mlx, data->win,
					data->tiles->full->img, x * data->texture_size, y * data->texture_size);
			else if (data->map_seg[y][x].oob == 0)
				mlx_put_image_to_window(data->mlx, data->win,
					data->map_seg[y][x].map_src->tile->img, x * data->texture_size, y
					* data->texture_size);
			}
			else
				mlx_put_image_to_window(data->mlx, data->win,
					data->tiles->flooded->img, x * data->texture_size, y * data->texture_size);
			x++;
		}
		y++;
	}
	return (0);
}
