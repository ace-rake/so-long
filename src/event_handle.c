/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:44:54 by vdenisse          #+#    #+#             */
/*   Updated: 2023/11/08 11:07:38 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_handle(int keycode, t_data **data_src)
{
	int	move;

	if (keycode == 'w' || keycode == 65362)
		move = UP;
	else if (keycode == 'a' || keycode == 65361)
		move = LEFT;
	else if (keycode == 's' || keycode == 65364)
		move = DOWN;
	else if (keycode == 'd' || keycode == 65363)
		move = RIGHT;
	else
		move = 0;
	move_start(*data_src, move);
}

int	key_handle_game(int keycode, t_data **data_src)
{
	t_data	*data;

	data = *data_src;
	if (keycode == 65307)
	{
		mlx_loop_end(data->mlx);
		return (0);
	}
	else if (keycode == 'w' || keycode == 'a' || keycode == 's'
		|| keycode == 'd' || keycode == 65361 || keycode == 65362
		|| keycode == 65363 || keycode == 65364)
		move_handle(keycode, data_src);
	return (1);
}
/*
int	key_handle(int keycode, t_data **data_src)
{
	t_data	*data;

	data = *data_src;
	if (keycode == 65307)
	{
		mlx_loop_end(data->mlx);
		return (0);
	}
	else if (keycode == 't')
	{
		(*data_src)->map_seg = get_map_segment(*data_src, 1);
		update_screen(data_src);
	}
	else if (keycode == 'm')
		update_screen(data_src);
	else if (keycode == 'p')
		game_start(data_src);
	return (1);
}
*/
int	click_close(t_data **data_src)
{
	t_data	*data;

	data = *data_src;
	mlx_loop_end(data->mlx);
	return (0);
}
