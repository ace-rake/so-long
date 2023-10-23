/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strform.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:06:42 by vdenisse          #+#    #+#             */
/*   Updated: 2023/10/23 13:34:51 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	ft_form(char **str, char *to_add, int iter, int to_free)
{
	int		len;
	char	*tmp;
	int		pos;

	len = ft_strlen(to_add) + ft_strlen(*str) - 2 + 1;
	tmp = (char *)malloc(len * sizeof(char));
	if (!tmp)
		return (1);
	ft_strlcpy(tmp, *str, (iter + 1) * sizeof(char));
	pos = iter;
	ft_strlcat(tmp + pos, to_add, ft_strlen(to_add) + 1);
	pos += ft_strlen(to_add);
	ft_strlcat(tmp + pos, *str + iter + 2, ft_strlen(*str) - (iter + 1));
	if (to_free)
		free(*str);
	*str = tmp;
	return (ft_strlen(to_add));
}

int	ft_strform(int to_free, char **str, ...)
{
	va_list	args;
	int		iter;

	va_start(args, str);
	iter = 0;
	while ((*str)[iter] != '\0')
	{
		if ((*str)[iter] == '%')
			iter += ft_form(str, va_arg(args, char *), iter, to_free);
		else
			iter++;
		to_free = 1;
	}
	va_end(args);
	return (0);
}
