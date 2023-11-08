/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:52:56 by vdenisse          #+#    #+#             */
/*   Updated: 2023/11/06 13:27:54 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	free_map(t_data *data, t_map **map)
{
	int	i;

	i = 0;
	while (i < data->max_y)
		free(map[i++]);
	free(map);
}

void	ft_free_tile(t_tile *tile)
{
	if (tile)
	{
		if (tile->texture_path)
			free(tile->texture_path);
		free(tile);
	}
}

void	ft_free_tile_set(t_tile_set *set)
{
	if (!set)
		return ;
	ft_free_tile(set->up);
	ft_free_tile(set->left);
	ft_free_tile(set->right);
	ft_free_tile(set->down);
	free(set);
}

void	tiles_free(t_tiles *tiles)
{
	ft_free_tile(tiles->obstacle);
	ft_free_tile(tiles->empty);
	ft_free_tile(tiles->collectible);
	ft_free_tile_set(tiles->player);
	ft_free_tile(tiles->start);
	ft_free_tile(tiles->end);
	ft_free_tile(tiles->flooded);
	ft_free_tile(tiles->full);
	if (tiles)
		free(tiles);
}

void	cleanup(t_data *data)
{
	if (data == NULL)
		return ;
	if (data->tiles != NULL)
		destroy_images(data, data->tiles);
	if (data->mlx != NULL)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	pthread_join(data->handler->thread, NULL);
	if (data->map)
		free_map(data, data->map);
	if (data->map_seg)
		map_seg_free(data->map_seg);
	tiles_free(data->tiles);
	free(data);
}
