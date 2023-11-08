/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:14:40 by vdenisse          #+#    #+#             */
/*   Updated: 2023/11/08 10:57:55 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <fcntl.h>

/*
void	print_map(t_map *map[], int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			printf("[%c]", map[j][i].tile->code);
			i++;
		}
		printf("\n");
		j++;
	}
	printf("\n");
}
*/
int	get_dimensions(char *map_src, int *x, int *y)
{
	int		fd;
	char	*new_read;

	*y = 0;
	fd = open(map_src, O_RDONLY);
	if (fd == -1)
		return (OPEN_ERR);
	new_read = get_next_line(fd, 0);
	*x = ft_strlen(new_read);
	while (new_read != NULL)
	{
		if ((int)ft_strlen(new_read) != *x)
		{
			free(new_read);
			free(get_next_line(fd, 1));
			close(fd);
			return (DIMENSION_ERR);
		}
		(*y)++;
		free(new_read);
		new_read = get_next_line(fd, 0);
	}
	(*x)--;
	close(fd);
	return (1);
}

int	malloc_map(t_map ***map, int x, int y)
{
	t_map	**new_map;
	int		iter;

	iter = 0;
	new_map = *map;
	new_map = (t_map **)malloc((y + 1) * sizeof(t_map **));
	if (!map)
		return (MALLOC_ERR);
	while (iter < y)
	{
		new_map[iter] = (t_map *)malloc((x) * sizeof(t_map));
		if (!new_map[iter++])
			return (MALLOC_ERR);
	}
	new_map[y] = NULL;
	*map = new_map;
	return (1);
}

int	line_to_map(t_map **map, char *new_read, t_tiles *tiles, int y)
{
	int	x;

	x = 0;
	while (x <= (int)ft_strlen(new_read) - 2)
	{
		map[y][x].tile = get_tile(new_read[x], tiles);
		if (map[y][x].tile == NULL)
			return (1);
		map[y][x].x = x;
		map[y][x].y = y;
		x++;
	}
	return (0);
}

int	map_to_map(t_map **map, char *map_src, t_tiles *tiles)
{
	int		fd;
	char	*new_read;
	int		line;

	line = 0;
	fd = open(map_src, O_RDONLY);
	new_read = get_next_line(fd, 0);
	if (!new_read)
		return (GNL_ERR);
	while (new_read != NULL)
	{
		if (line_to_map(map, new_read, tiles, line))
		{
			free(new_read);
			free(get_next_line(fd, 1));
			close(fd);
			return (GET_TILE_ERR);
		}
		free(new_read);
		new_read = get_next_line(fd, 0);
		line++;
	}
	close(fd);
	return (1);
}

int	map_parse(t_data **data_src, char *map_src, t_tiles *tiles)
{
	t_data	*data;
	int		fd;
	int		err;

	data = *data_src;
	data->map = NULL;
	fd = open(map_src, O_RDONLY);
	close(fd);
	err = 1;
	err *= check_extension(map_src);
	if (fd == -1)
		return (INVALID_NAME_ERR * err);
	err *= get_dimensions(map_src, &data->max_x, &data->max_y);
	if (err % DIMENSION_ERR == 0)
		return (err);
	err *= malloc_map(&data->map, data->max_x, data->max_y);
	if (err % MALLOC_ERR == 0)
		return (err);
	err *= map_to_map(data->map, map_src, tiles);
	if (err % GET_TILE_ERR == 0)
		return (err);
	err *= map_check(data->max_x, data->max_y, data);
	if (err != 1)
		return (err);
	return (0);
}
