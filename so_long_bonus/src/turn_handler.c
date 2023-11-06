/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:02:39 by vdenisse          #+#    #+#             */
/*   Updated: 2023/11/06 14:36:32 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	*turn_handler(void  *arg)
{
	printf("handler start\n");
	t_data *data;
	t_handler *handler;

	data = (t_data *)arg;
	handler = data->handler;
	*handler->done = 0;
	while (*handler->start != 1)
	{
		printf("wait [%d]\n", *handler->start);
		usleep(1);
	}
	while (*handler->done == 0)
	{
		if (*data->game_info.next_move != NONE)
			move_start(data, *data->game_info.next_move);
		*data->game_info.next_move = NONE;
		update_screen(&data);
		usleep(10000);
		printf("handler check move := [%d]\n", *handler->done);
	}
	printf("handler end\n");
	return (NULL);
}
