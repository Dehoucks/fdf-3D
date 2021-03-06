/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdehouck <rdehouck@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:46:24 by robindehouc       #+#    #+#             */
/*   Updated: 2022/02/18 16:14:13 by rdehouck         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			ft_paint(t_param **mlx, int x, int y)
{
	mlx_pixel_put((*mlx)->id, (*mlx)->win, x, y, (*mlx)->color);
}

static void		alloc_tab(t_param **mlx)
{
	int		i;

	i = 0;
	(*mlx)->tab = (int**)ft_memalloc(sizeof(int*) * (*mlx)->nline);
	while (i < (*mlx)->nline)
	{
		(*mlx)->tab[i] = (int*)ft_memalloc(sizeof(int) * (*mlx)->ncol);
		i++;
	}
}

// Here we will send to atoi for example the index corresponding to 1, and if the index++ == 0 && index++ == ' '
// then tab[x][y] == 10
// because atoi will read until finding a space.

void			map_to_tab(t_param **mlx, char *map)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	x = 0;
	y = 0;
	alloc_tab(mlx);
	verif_content((*mlx)->tab);
	i = 0;
	while (x < (*mlx)->nline)
	{
		y = 0;
		while (y < (*mlx)->ncol)
		{
			while (map[i] && ft_isspace(map[i]) == 1)
				i++;
			(*mlx)->tab[x][y] = ft_atoi(&map[i]);
			while (map[i] && ft_isspace(map[i]) == 0)
				i++;
			y++;
		}
		x++;
	}
}

char			*map_to_string(char *argv, t_param **mlx)
{
	int		fd;
	int		ret;
	char	*line;
	char	*tmp;
	char	*map;

	line = NULL;
	tmp = NULL;
	map = NULL;
	if (!(map = ft_memalloc(sizeof((*mlx)->ncol * (*mlx)->nline) + 1)))
		exit(EXIT_FAILURE);
	fd = open(argv, O_RDONLY);
	verif_fd(fd);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		tmp = ft_strdup(line);
		map = ft_strjoinfree(map, tmp, 1);
		map = ft_strjoinfree(map, " ", 1);
		ft_strdel(&line);
		ft_strdel(&tmp);
	}
	if (tmp)
		ft_strdel(&tmp);
	close(fd);
	return (map);
}
