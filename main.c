/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:32:46 by vdenisse          #+#    #+#             */
/*   Updated: 2023/11/08 10:31:35 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_perror(int err)
{
	if (err % IMAGE_CREATION_ERR == 0)
		write(1, "image_creation_error\n", 21);
	if (err % EXTENTION_ERR == 0)
		write(1, "extention_error\n", 16);
	if (err % DIMENSION_ERR == 0)
		write(1, "dimension_error\n", 16);
	if (err % MAP_CONTENT_ERR == 0)
		write(1, "map_content_error\n", 18);
	if (err % INVALID_NAME_ERR == 0)
		write(1, "invalid_name_error\n", 19);
	if (err % INVALID_OUTER_WALL == 0)
		write(1, "invalid outer wall\n", 19);
	if (err % INVALID_CONTENT == 0)
		write(1, "invalid content\n", 16);
	if (err % INCOMPLETABLE == 0)
		write(1, "incompletable\n", 14);
	if (err % OPEN_ERR == 0)
		write(1, "open err\n", 9);
	if (err % MALLOC_ERR == 0)
		write(1, "malloc err\n", 11);
	if (err % GNL_ERR == 0)
		write(1, "gnl err\n", 8);
	if (err % GET_TILE_ERR == 0)
		write(1, "get tile err\n", 12);
}

int	main(int argc, char *argv[])
{
	t_tiles	*tiles;
	t_data	*data;
	int		returns;

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
