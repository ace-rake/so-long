/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_segmenter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:13:51 by vdenisse          #+#    #+#             */
/*   Updated: 2023/10/17 10:47:15 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
void	print_map_seg(t_map_seg **map_seg, int max_y, int max_x)
{
	int	iter;
	int	jter;

	printf("enter map seg print\n");
	iter = 0;
	while (iter < max_y)
	{
		jter = 0;
		while (jter < max_x)
		{
			if (map_seg[iter][jter].oob == 0)
				printf("[%c]", map_seg[iter][jter].map_src->tile->code);
			else
				printf("[9]");
			jter++;
		}
		iter++;
		printf("\n");
	}
}
*/
t_map_seg	**map_seg_malloc(int y, int x)
{
	t_map_seg	**map_seg;
	int			iter;

	iter = 0;
	map_seg = (t_map_seg **)malloc((y + 1) * sizeof(t_map_seg *));
	while (iter <= y)
	{
		map_seg[iter] = (t_map_seg *)malloc((x + 1) * sizeof(t_map_seg));
		iter++;
	}
	return (map_seg);
}

void	map_seg_free(t_map_seg **map_seg)
{
	int	y;

	y = 0;
	while (y <= 8)
	{
		free(map_seg[y]);
		++y;
	}
	free(map_seg);
}

void	map_segmenter_center(t_data *data, t_map_seg **map_seg, int x, int y)
{
	t_map	**map;
	int		iter;
	int		jter;

	iter = -3;
	map = data->map;
	while (iter < 5)
	{
		jter = -7;
		while (jter < 8)
		{
			map_seg[iter + 3][jter + 7].oob = 0;
			if (y + iter >= 0 && x + jter >= 0 && x + jter < data->max_x && y
				+ iter < data->max_y)
				map_seg[iter + 3][jter + 7].map_src = &(map[y + iter][x
						+ jter]);
			else
				map_seg[iter + 3][jter + 7].oob = 1;
			map_seg[iter + 3][jter + 7].curr_x = jter + 7;
			map_seg[iter + 3][jter + 7].curr_y = iter + 3;
			map_seg[iter + 3][jter + 7].to_update = 1;
			jter++;
		}
		iter++;
	}
}

t_map_seg	**get_map_segment(t_data *data, int create)
{
	t_map_seg	**map_seg;
	int			x;
	int			y;

	if (create)
		map_seg = map_seg_malloc(8, 15);
	else
		map_seg = data->map_seg;
	x = 0;
	y = 0;
	finder(data, &y, &x, data->tiles->player->up->code);
	map_segmenter_center(data, map_seg, x, y);
	return (map_seg);
}
