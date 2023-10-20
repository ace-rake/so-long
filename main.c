/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:32:46 by vdenisse          #+#    #+#             */
/*   Updated: 2023/10/20 15:32:04 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_perror(int err)
{
	if (err == IMAGE_CREATION_ERR)
		write(1, "image_creation_error\n", 21);
	if (err == EXTENTION_ERR)
		write(1, "extention_error\n", 16);
	if (err == DIMENSION_ERR)
		write(1, "dimension_error\n", 16);
}

int	main(int argc, char *argv[])
{
	t_tiles	*tiles;
	t_data	*data;
	int	returns;

	if (argc != 2)
		return (0);
	data = (t_data *)malloc(sizeof(t_data));
	tiles = tiles_init();
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
