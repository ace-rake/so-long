/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:41:55 by vdenisse          #+#    #+#             */
/*   Updated: 2023/11/07 13:12:51 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"
void	*ft_realloc(void *prev, size_t new_size)
{
	void	*result;

	if (new_size == 0)
	{
		if (prev)
			free(prev);
		return (NULL);
	}
	result = malloc(new_size);
	if (!result)
		return (NULL);
	if (prev == NULL)
		return (result);
	ft_memmove(result, prev, ft_strlen((const char *) prev));
	free(prev);
	return (result);
}

void	*ft_reallocarray(void *ptr, size_t nmemb, size_t size)
{
	return (ft_realloc(ptr, nmemb * size));
}
