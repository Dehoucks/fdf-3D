/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdehouck <rdehouck@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:46:30 by robindehouc       #+#    #+#             */
/*   Updated: 2022/02/18 16:03:44 by rdehouck         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_struct_mlx(t_param **mlx)
{
	(*mlx)->id = NULL;
	(*mlx)->win = NULL;
	(*mlx)->tab = NULL;
	(*mlx)->height = 1600;
	(*mlx)->width = 960;
	(*mlx)->alt = 2;
	(*mlx)->nline = 0;
	(*mlx)->ncol = 0;
	(*mlx)->color = 0xFFFFFF;
	(*mlx)->shift_x = 200;
	(*mlx)->shift_y = 200;
	(*mlx)->zoom = 0.5;
}

void	init_struct_coord(t_coord *pos)
{
	pos->x1 = 0;
	pos->y1 = 0;
	pos->x2 = 0;
	pos->y2 = 0;
}
