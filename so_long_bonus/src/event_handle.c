/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:44:54 by vdenisse          #+#    #+#             */
/*   Updated: 2023/11/06 14:32:28 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	move_handle(int keycode, t_data **data_src)
{
	t_data *data;

	data = *data_src;
	if (keycode == 'w' || keycode == 65362)
		*data->game_info.next_move = UP;
	else if (keycode == 'a' || keycode == 65361)
		*data->game_info.next_move = LEFT;
	else if (keycode == 's' || keycode == 65364)
		*data->game_info.next_move = DOWN;
	else if (keycode == 'd' || keycode == 65363)
		*data->game_info.next_move = RIGHT;
	else
		*data->game_info.next_move = NONE;
}

int	key_handle_game(int keycode, t_data **data_src)
{
	t_data	*data;

	data = *data_src;
	if (keycode == 65307)
	{
		exit_sequence(data);
		return (0);
	}
	else if (keycode == 'w' || keycode == 'a' || keycode == 's'
		|| keycode == 'd' || keycode == 65361 || keycode == 65362
		|| keycode == 65363 || keycode == 65364)
		move_handle(keycode, data_src);
	else if (keycode == 'u')
		*data->handler->done = 1;
	else if (keycode == 't')
		turn_handler(data);
	else
		printf("%c:%d was pressed but nothing is bound\n", keycode, keycode);
	return (1);
}

int	key_handle(int keycode, t_data **data_src)
{
	t_data	*data;

	data = *data_src;
	printf("%c was pressed\n", keycode);
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
	else
	{
		printf(" but nothing is bound\n");
	}
	return (1);
}

int	click_close(t_data **data_src)
{
	t_data	*data;

	data = *data_src;
	mlx_loop_end(data->mlx);
	return (0);
}
