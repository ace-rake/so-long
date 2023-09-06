/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:30:16 by vdenisse          #+#    #+#             */
/*   Updated: 2023/08/10 15:54:23 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	update_screen(t_data **data_src, int missing)
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
			if (data->map_seg[y][x].oob == 0)
				mlx_put_image_to_window(data->mlx, data->win,
					data->map_seg[y][x].map_src->tile->img, x * 128, y
					* 128);
			else
				mlx_put_image_to_window(data->mlx, data->win,
					data->tiles->flooded->img, x * 128, y * 128);
			x++;
		}
		y++;
	}
	(void)missing;
	return (0);
}
