/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:30:09 by vdenisse          #+#    #+#             */
/*   Updated: 2023/09/25 13:09:33 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
/*
int	player_finder_seg(t_data *data, int *y, int *x)
{
	*y = 0;
	while (*y < 8)
	{
		*x = 0;
		while (*x < 15)
		{
			if (data->map_seg[*y][*x].oob == 0)
				if (data->map_seg[*y][*x].map_src->tile->code == 'P'
					|| data->map_seg[*y][*x].map_src->tile->code == 'R')
					return (1);
			(*x)++;
		}
		(*y)++;
	}
	return (0);
}
*/
int	move_invalid(t_data *data, int move)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!finder(data, &y, &x, data->tiles->player->up->code))
		return (1);
	if (move == LEFT || move == RIGHT)
	{
		if (data->map[y][x + move].tile->code == '1')
			return (1);
	}
	else if (move == UP || move == DOWN)
	{
		move /= 10;
		if (data->map[y + move][x].tile->code == '1')
			return (1);
	}
	return (0);
}

void	change_tiles(t_data *data, t_map *start, t_map *end, int mv_cpy)
{
	if (data->game_info.stand_on_tile->code == data->tiles->collectible->code)
		(*start).tile = data->tiles->empty;
	else
		(*start).tile = data->game_info.stand_on_tile;
	if (end->tile == data->tiles->collectible)
		data->game_info.collectibles_collected++;
	data->game_info.stand_on_tile = end->tile;
	if (mv_cpy == UP)
		end->tile = data->tiles->player->up;
	if (mv_cpy == RIGHT)
		end->tile = data->tiles->player->right;
	if (mv_cpy == DOWN)
		end->tile = data->tiles->player->down;
	if (mv_cpy == LEFT)
		end->tile = data->tiles->player->left;
}

int	check_end(t_game_info game_info)
{
	if (game_info.total_collectibles == game_info.collectibles_collected)
	{
		printf("game_succes\n");
		return (1);
	}
	printf("fuck outta here\n");
	return (0);
}

int	move_player(t_data *data, int move)
{
	int		x;
	int		y;
	t_map	*end;
	t_map	*start;
	int		mv_cpy;

	mv_cpy = move;
	x = 0;
	y = 0;
	finder(data, &y, &x, data->tiles->player->up->code);
	start = &data->map[y][x];
	if (move == LEFT || move == RIGHT)
		end = &data->map[y][x + move];
	else
	{
		move /= 10;
		end = &data->map[y + move][x];
	}
	change_tiles(data, start, end, mv_cpy);
	if (data->game_info.stand_on_tile == data->tiles->end)
		if (check_end(data->game_info))
			mlx_loop_end(data->mlx);
	return (0);
}

/*
int	move_start_no_tex(t_data *data, int move)
{
	if (move_invalid(data, move))
	{
		printf("invalid move\n");
		return (1);
	}
	move_player(data, move);
	return (0);
}
*/
int	move_start(t_data *data, int move)
{
	int	x;
	int	y;

	if (move_invalid(data, move))
		return (1);
	finder(data, &y, &x, data->tiles->player->up->code);
	printf("step count : [%d]\n", ++data->game_info.step_count);
	move_player(data, move);
	printf("[%d] collected out of [%d]\n",
		data->game_info.collectibles_collected,
		data->game_info.total_collectibles);
	data->map_seg = get_map_segment(data, 0);
	update_screen(&data, 0);
	return (0);
}
