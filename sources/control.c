/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdehouck <rdehouck@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:46:01 by robindehouc       #+#    #+#             */
/*   Updated: 2022/03/09 16:08:39 by rdehouck         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		verif_line(char *line, int i, t_param **mlx)
{
	int		j;

	j = 0;
	if (i == 0)
		(*mlx)->ncol = ft_countword(line, ' ');
	if (i != 0)
	{
		j = ft_countword(line, ' ');
		if (j != (*mlx)->ncol)
		{
			ft_putendl("The file provided is not correctly formated.");
			return (1);
		}
	}
	return (0);
}

void			verif_fd(int fd)
{
	if (fd < 0)
	{
		ft_putendl("opening_error");
		exit(EXIT_FAILURE);
	}
}

int				check_map(char *map, t_param **mlx)
{
	int		fd;
	int		ret;
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	fd = open(map, O_RDONLY);
	verif_fd(fd);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (verif_line(line, i, mlx) != 0)
		{
			close(fd);
			ft_strdel(&line);
			return (1);
		}
		i++;
		ft_strdel(&line);
	}
	(*mlx)->nline = i;
	close(fd);
	return (0);
}
