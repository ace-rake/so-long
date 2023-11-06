/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:11:01 by vdenisse          #+#    #+#             */
/*   Updated: 2023/11/02 14:11:34 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_images(t_data *data, t_tiles *tiles)
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
