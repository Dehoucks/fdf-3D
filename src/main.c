/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:46:13 by robindehouc       #+#    #+#             */
/*   Updated: 2022/02/17 22:46:15 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		verif_arg(char *argv)
{
	int		i;

	i = ft_strlenint(argv) - 4;
	if (ft_strcmp(&argv[i], ".fdf") == 0)
		return (1);
	else
		return (0);
}

int				main(int argc, char **argv)
{
	t_param		*mlx;
	char		*map;

	map = NULL;
	mlx = (t_param*)malloc(sizeof(t_param));
	init_struct_mlx(&mlx);
	if (argc != 2)
		view_usage(1, &mlx);
	else
	{
		if (verif_arg(argv[1]) != 0)
		{
			if (check_map(argv[1], &mlx) != 0)
				exit(EXIT_FAILURE);
			else
				map = map_to_string(argv[1], &mlx);
			map_to_tab(&mlx, map);
			ft_strdel(&map);
			init_mlx(&mlx);
			core(&mlx);
		}
		else
			ft_putendl("No data found.");
	}
	return (0);
}
