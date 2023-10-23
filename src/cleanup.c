/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:52:56 by vdenisse          #+#    #+#             */
/*   Updated: 2023/10/23 14:43:36 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

static void	destroy_images(t_data *data, t_tiles *tiles)
{
	if (tiles->obstacle->img != NULL)
		mlx_destroy_image(data->mlx, tiles->obstacle->img);
	if (tiles->empty->img != NULL)
		mlx_destroy_image(data->mlx, tiles->empty->img);
	if (tiles->collectible->img != NULL)
		mlx_destroy_image(data->mlx, tiles->collectible->img);
	if (tiles->player->up->img != NULL)
		mlx_destroy_image(data->mlx, tiles->player->up->img);
	if (tiles->player->right->img != NULL)
		mlx_destroy_image(data->mlx, tiles->player->right->img);
	if (tiles->player->down->img != NULL)
		mlx_destroy_image(data->mlx, tiles->player->down->img);
	if (tiles->player->left->img != NULL)
		mlx_destroy_image(data->mlx, tiles->player->left->img);
	if (tiles->start->img != NULL)
		mlx_destroy_image(data->mlx, tiles->start->img);
	if (tiles->end->img != NULL)
		mlx_destroy_image(data->mlx, tiles->end->img);
	if (tiles->flooded->img != NULL)
		mlx_destroy_image(data->mlx, tiles->flooded->img);
	if (tiles->full->img != NULL)
		mlx_destroy_image(data->mlx, tiles->full->img);
}

void	ft_free_tile(t_tile *tile)
{
	if (tile)
	{
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
	printf("cleanup start\n");
	if (data->tiles->obstacle->img != NULL)
		destroy_images(data, data->tiles);
	if (data->mlx != NULL)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->map)
		free_map(data, data->map);
	if (data->map_seg)
		map_seg_free(data->map_seg);
	tiles_free(data->tiles);
	free(data);
	printf("cleanup end\n");
}
