/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:32:46 by vdenisse          #+#    #+#             */
/*   Updated: 2023/11/06 13:39:37 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <stdio.h>

void	ft_perror(int err)
{
	if (err == IMAGE_CREATION_ERR)
		write(1, "image_creation_error\n", 21);
	else if (err == EXTENTION_ERR)
		write(1, "extention_error\n", 16);
	else if (err == DIMENSION_ERR)
		write(1, "dimension_error\n", 16);
	else if (err == MAP_CONTENT_ERR)
		write(1, "map_content_error\n", 18);
	else if (err == INVALID_NAME_ERR)
		write(1, "invalid_name_error\n", 19);
	else
		write(1, "Error\n", 6);
}

t_handler	*handler_init(void)
{
	t_handler *handler;

	handler = (t_handler *)malloc(sizeof(t_handler) * 1);
	handler->done = (int *)malloc(sizeof(int) * 1);
	*handler->done = 0;
	handler->next_move = (int *)malloc(sizeof(int) * 1);
	*handler->next_move = NONE;
	handler->start = (int *)malloc(sizeof(int) * 1);
	*handler->start = 0;
	return (handler);
}

int	data_init(t_data **data_src)
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data) * 1);
	if (!data)
		return (1);
	*data_src = data;
	data->game_info.next_move = (int *)malloc(sizeof(int) * 1);
	if (!data->game_info.next_move)
		return (1);
	*data->game_info.next_move = NONE;
	data->handler = handler_init();
	return (0);
}

#include <pthread.h>
int	thread_init(t_data *data)
{
	pthread_create(&data->handler->thread, NULL, turn_handler, data);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_tiles	*tiles;
	t_data	*data;
	int		returns;

	if (argc != 2)
		return (0);
	tiles = tiles_init();
	if (data_init(&data))
	{
		cleanup(data);
		return (0);
	}
	data->tiles = tiles;
	data->map = NULL;
	returns = 0;
	if (argc >= 1)
		returns = map_parse(&data, argv[1], tiles);
	if (returns == 0)
		returns = master(data);
	if (returns != 0)
		ft_perror(returns);
	cleanup(data);
	return (0);
}
