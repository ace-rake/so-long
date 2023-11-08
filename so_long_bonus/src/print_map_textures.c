/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:30:16 by vdenisse          #+#    #+#             */
/*   Updated: 2023/11/06 11:38:40 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	print_single_texture(t_map_seg **map_seg, t_data *d, int x, int y)
{
	t_tiles	*tiles;

	tiles = d->tiles;
	if (d->map_seg[y][x].oob != 1)
	{
		if (d->game_info.stand_on_tile == d->tiles->end
			&& map_seg[y][x].map_src->tile->code == tiles->player->up->code)
			mlx_put_image_to_window(d->mlx, d->win, d->tiles->full->img, x
				* d->texture_size, y * d->texture_size);
		else if (d->game_info.stand_on_tile == d->tiles->start
			&& map_seg[y][x].map_src->tile->code == tiles->player->up->code)
			mlx_put_image_to_window(d->mlx, d->win, tiles->full->img, x
				* d->texture_size, y * d->texture_size);
		else if (map_seg[y][x].oob == 0)
			mlx_put_image_to_window(d->mlx, d->win,
				map_seg[y][x].map_src->tile->img, x * d->texture_size, y
				* d->texture_size);
	}
	else
		mlx_put_image_to_window(d->mlx, d->win, tiles->flooded->img, x
			* d->texture_size, y * d->texture_size);
}

int	update_screen(t_data **d_s)
{
	int		y;
	int		x;
	t_data	*d;

	d = *d_s;
	y = 0;
	while (y < 8)
	{
		x = 0;
		while (x < 15)
		{
			print_single_texture(d->map_seg, d, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
