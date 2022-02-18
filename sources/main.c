/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdehouck <rdehouck@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:46:13 by robindehouc       #+#    #+#             */
/*   Updated: 2022/02/18 16:19:15 by rdehouck         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				main(int argc, char **argv)
{
	t_param		*mlx;
	char		*land;

	mlx = (t_param*)malloc(sizeof(t_param));
	init_struct_mlx(&mlx);
	if (argc != 2)
		view_usage(1, &mlx);
	else
	{
		check_map(argv[1], &mlx);
		land = map_to_string(argv[1], &mlx);
		map_to_tab(&mlx, land);
		ft_strdel(&land);
		init_mlx(&mlx);
		ft_factory(&mlx);
	}
	return (0);
}
