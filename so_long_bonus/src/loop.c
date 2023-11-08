/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:12:12 by vdenisse          #+#    #+#             */
/*   Updated: 2023/11/06 11:38:39 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

/*
void	create_image(t_data *data_src)
{
	t_data			data;
	int				width;
	int				height;
	unsigned char	red;
	unsigned char	blue;
	int				pixel_index;

	data = *data_src;
	width = 1000;
	height = 1002;
	red = 0xFF;
	red -= *data.ofset;
	blue = 0xFF;
	blue += *data.ofset;
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			pixel_index = (x * data.img_data.line_length) + (y
					* (data.img_data.bits_per_pixel / 8));
			data.img_data.image_data[pixel_index] = blue;     // Blue channel
			data.img_data.image_data[pixel_index + 1] = 0x00; // Green channel
			data.img_data.image_data[pixel_index + 2] = red;  // Red channel
			data.img_data.image_data[pixel_index + 3] = 0x00;
			// Alpha channel (if applicable)
			red--;
			blue++;
		}
	}
}

int	red_blue_loop(t_data *data_src)
{
	t_data	data;

	data = *data_src;
	create_image(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	(*data.ofset)++;
	usleep(111111);
	return (0);
}

void	loop(void)
{
	t_data	data;
	int		ofset;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1000, 1000, "Hello world!");
	data.img = mlx_new_image(data.mlx, 1000, 1000);
	data.img_data.image_data = mlx_get_data_addr(data.img,
													&data.img_data.bits_per_pixel,
													&data.img_data.line_length,
													&data.img_data.endian);
	ofset = 0;
	data.ofset = &ofset;
	mlx_loop_hook(data.mlx, red_blue_loop, &data);
	mlx_hook(data.win, 17, 0, click_close, &data);
	mlx_key_hook(data.win, key_handle, &data);
	mlx_loop(data.mlx);
	cleanup(data);
}
*/
