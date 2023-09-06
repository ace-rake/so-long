/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:30:04 by vdenisse          #+#    #+#             */
/*   Updated: 2023/08/10 11:43:20 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	char *line;
	int fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd, 1);
	free(line);
	close(fd);
	(void)argc;
}
