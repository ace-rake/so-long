/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:32:46 by vdenisse          #+#    #+#             */
/*   Updated: 2023/09/25 11:18:14 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_tiles	*tiles;
	t_data	*data;

	if (argc != 2)
		return (0);
	data = (t_data *)malloc(sizeof(t_data));
	tiles = tiles_init();
	data->tiles = tiles;
	data->map = NULL;
	if (argc >= 1)
	{
		if (map_parse(&data, argv[1], tiles))
		{
			printf("error\n");
			cleanup(data);
			return (1);
		}
	}
	master(data);
	cleanup(data);
	return (0);
}
