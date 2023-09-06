/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:54:55 by vdenisse          #+#    #+#             */
/*   Updated: 2023/06/01 11:57:51 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*next;
	t_list	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	while (tmp != NULL)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*lst = NULL;
}
