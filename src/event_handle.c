/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:44:54 by vdenisse          #+#    #+#             */
/*   Updated: 2023/09/05 12:09:24 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_handle(int keycode, t_data **data_src)
{
	int	move;

	if (keycode == 'w')
		move = UP;
	else if (keycode == 'a')
		move = LEFT;
	else if (keycode == 's')
		move = DOWN;
	else if (keycode == 'd')
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
		printf("esc pressed\n");
		mlx_loop_end(data->mlx);
		return (0);
	}
	else if (keycode == 'w' || keycode == 'a' || keycode == 's'
		|| keycode == 'd')
		move_handle(keycode, data_src);
	else
		printf("%c was pressed but nothing is bound\n", keycode);
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
		update_screen(data_src, 0);
	}
	else if (keycode == 'm')
		update_screen(data_src, 1);
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
