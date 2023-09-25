/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:52:56 by vdenisse          #+#    #+#             */
/*   Updated: 2023/09/25 13:10:45 by vdenisse         ###   ########.fr       */
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

void	destroy_images(t_data *data, t_tiles *tiles)
{
	mlx_destroy_image(data->mlx, tiles->obstacle->img);
	mlx_destroy_image(data->mlx, tiles->empty->img);
	mlx_destroy_image(data->mlx, tiles->collectible->img);
	mlx_destroy_image(data->mlx, tiles->player->up->img);
	mlx_destroy_image(data->mlx, tiles->player->right->img);
	mlx_destroy_image(data->mlx, tiles->player->down->img);
	mlx_destroy_image(data->mlx, tiles->player->left->img);
	mlx_destroy_image(data->mlx, tiles->start->img);
	mlx_destroy_image(data->mlx, tiles->end->img);
	mlx_destroy_image(data->mlx, tiles->flooded->img);
}

void	tiles_free(t_tiles *tiles)
{
	if (tiles->obstacle)
		free(tiles->obstacle);
	if (tiles->empty)
		free(tiles->empty);
	if (tiles->collectible)
		free(tiles->collectible);
	if (tiles->player)
		free(tiles->player);
	if (tiles->start)
		free(tiles->start);
	if (tiles->end)
		free(tiles->end);
	if (tiles->flooded)
		free(tiles->flooded);
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
