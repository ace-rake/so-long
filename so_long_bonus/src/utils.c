/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:09:31 by vdenisse          #+#    #+#             */
/*   Updated: 2023/11/06 11:38:40 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	finder(t_data *data, int *y, int *x, char code)
{
	*y = 0;
	while (*y < data->max_y)
	{
		*x = 0;
		while (*x < data->max_x)
		{
			if (data->map[*y][*x].tile->code == code)
			{
				return (1);
			}
			(*x)++;
		}
		(*y)++;
	}
	return (0);
}

int	check_extension(char *map_src)
{
	while (*map_src != '.')
		map_src++;
	if (ft_strncmp(map_src, ".ber\0", 5) == 0)
		return (0);
	return (1);
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
