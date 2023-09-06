/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:14:40 by vdenisse          #+#    #+#             */
/*   Updated: 2023/08/10 15:51:58 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <fcntl.h>

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

int	get_dimensions(char *map_src, int *x, int *y)
{
	int		fd;
	char	*new_read;

	*y = 0;
	fd = open(map_src, O_RDONLY);
	if (fd == -1)
		return (1);
	new_read = get_next_line(fd, 0);
	*x = ft_strlen(new_read);
	while (new_read != NULL)
	{
		if ((int)ft_strlen(new_read) != *x)
		{
			free(new_read);
			free(get_next_line(fd, 1));
			close(fd);
			return (1);
		}
		(*y)++;
		free(new_read);
		new_read = get_next_line(fd, 0);
	}
	(*x)--;
	close(fd);
	return (0);
}

int	malloc_map(t_map ***map, int x, int y)
{
	t_map	**new_map;
	int		iter;

	iter = 0;
	new_map = *map;
	new_map = (t_map **)malloc((y + 1) * sizeof(t_map **));
	if (!map)
		return (1);
	while (iter < y)
	{
		new_map[iter] = (t_map *)malloc((x) * sizeof(t_map));
		if (!new_map[iter++])
			return (1);
	}
	new_map[y] = NULL;
	*map = new_map;
	return (0);
}

t_tile	*get_tile(char c, t_tiles *tiles)
{
	if (c == tiles->obstacle->code)
		return (tiles->obstacle);
	if (c == tiles->empty->code)
		return (tiles->empty);
	if (c == tiles->collectible->code)
		return (tiles->collectible);
	if (c == tiles->player->up->code)
		return (tiles->player->up);
	if (c == tiles->start->code)
		return (tiles->start);
	if (c == tiles->end->code)
		return (tiles->end);
	return (NULL);
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
		return (1);
	while (new_read != NULL)
	{
		if (line_to_map(map, new_read, tiles, line))
		{
			free(new_read);
			free(get_next_line(fd, 1));
			close(fd);
			return (1);
		}
		free(new_read);
		new_read = get_next_line(fd, 0);
		line++;
	}
	close(fd);
	return (0);
}

void	free_map(t_data *data, t_map **map)
{
	int	i;

	i = 0;
	while (i < data->max_y)
	{
		free(map[i++]);
	}
	free(map);
}

int	check_extension(char *map_src)
{
	while (*map_src != '.')
		map_src++;
	if (ft_strncmp(map_src, ".ber\0", 5) == 0)
		return (0);
	return (1);
}

int	map_parse(t_data **data_src, char *map_src, t_tiles *tiles)
{
	t_map	**map;
	t_data	*data;

	map = NULL;
	data = *data_src;
	data->map = map;
	if (check_extension(map_src))
		return (1);
	if (get_dimensions(map_src, &data->max_x, &data->max_y))
		return (1);
	if (malloc_map(&data->map, data->max_x, data->max_y))
		return (1);
	if (map_to_map(data->map, map_src, tiles))
		return (1);
	if (map_check(data->max_x, data->max_y, data))
		return (1);
	return (0);
}
