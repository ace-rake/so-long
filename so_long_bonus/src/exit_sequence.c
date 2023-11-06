/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_sequence.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:21:09 by vdenisse          #+#    #+#             */
/*   Updated: 2023/11/06 14:26:09 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	exit_sequence(t_data *data)
{
	*data->handler->done = 1;
	if (pthread_join(data->handler->thread, NULL))
	{
		printf("HMMi\n");
	}
	usleep(500000);
	mlx_loop_end(data->mlx);
}
