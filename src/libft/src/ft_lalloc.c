/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lalloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:39:02 by vdenisse          #+#    #+#             */
/*   Updated: 2023/11/07 13:47:59 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

#include <stdio.h>

static void	free_memkeeper(t_memkeeper *saved)
{
	int i;

	i = 0;
	while (i < saved->mem_amount)
	{
		free(saved->memarray[i]);
		i++;
	}
	free(saved->memarray);
}

static void	update_memkeeper(t_memkeeper *saved, void *new)
{
	saved->memarray = ft_reallocarray(saved->memarray, saved->mem_amount + 1, sizeof(void *));
	saved->memarray[saved->mem_amount] = new;
	saved->mem_amount++;
}

void	*ft_lalloc(size_t size)
{
	void	*result;
	static t_memkeeper	saved = {NULL, 0};

	if (size == 0)
	{
		free_memkeeper(&saved);
		return (NULL);
	}
	result = malloc(size);
	if (!result)
		return (NULL);
	update_memkeeper(&saved, result);
	return (result);
}

void	free_mem(void)
{
	ft_lalloc(0);
}
