/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdehouck <rdehouck@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:46:07 by robindehouc       #+#    #+#             */
/*   Updated: 2022/03/09 13:19:53 by rdehouck         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// In case x1 > x2, then we will switch p1 with p2
// We act accordingly because the pixel_linker has been created to print_pix from left to right
static void		verif(t_coord **pos)
{
	int		tmp;

	if ((*pos)->x1 > (*pos)->x2)
	{
		tmp = (*pos)->x1;
		(*pos)->x1 = (*pos)->x2;
		(*pos)->x2 = tmp;
		tmp = (*pos)->y1;
		(*pos)->y1 = (*pos)->y2;
		(*pos)->y2 = tmp;
	}
}

static void		pixel_linker2(t_coord **pos, t_param **mlx, int dx, int dy)
{
	int		e;
	int		i;

	i = (dx >= -dy);
	e = i ? dx : dy;
	dx = i ? e * 2 : dx * 2;
	dy = i ? dy * 2 : e * 2;
	while (i ? (*pos)->x1 < (*pos)->x2 : (*pos)->y1 > (*pos)->y2)
	{
		mlx_pixel_put((*mlx)->id, (*mlx)->win, (*pos)->x1, (*pos)->y1,
				(*mlx)->color);
		e = i ? e + dy : e + dx;
		if (i ? e < 0 : e > 0)
		{
			i ? (*pos)->y1-- : (*pos)->x1++;
			e = i ? e + dx : e + dy;
		}
		i ? (*pos)->x1++ : (*pos)->y1--;
	}
}

static void		assign_values(int e, int dx, int dy)
{
	e = (dx >= dy) ? dx : dy;
	dx = (dx >= dy) ? e * 2 : dx * 2;
	dy = (dx >= dy) ? dy * 2 : e * 2;
}

// draw function will print a segment between two points, pixel by pixel.
// for eg. : p1(775; 485)
//           p2(800; 490)
// print_pix(775; 485), then print_pix(776:486) ... print_pix(x1++: y1++) ... print_pix (800; 490)
void			pixel_linker(t_coord **pos, t_param **mlx)
{
	int		dx;
	int		dy;
	int		e;

	verif(pos);
	e = 0;
	dy = (*pos)->y2 - (*pos)->y1;
	dx = (*pos)->x2 - (*pos)->x1;
	// printf("dx = %d // dy = %d\n", dx, dy);
	if (dy >= 0)
	{
		while ((*pos)->x1 < (*pos)->x2)
		{
			assign_values(e, dx, dy);
			ft_paint(mlx, (*pos)->x1, (*pos)->y1);
			if ((e = (dx >= dy) ? e - dy : e - dx) < 0)
			{
				(dx >= dy) ? (*pos)->y1++ : (*pos)->x1++;
				e = (dx >= dy) ? e + dx : e + dy;
			}
			(dx >= dy) ? (*pos)->x1++ : (*pos)->y1++;
		}
	}
	else
		pixel_linker2(pos, mlx, dx, dy);
	ft_paint(mlx, (*pos)->x2, (*pos)->y2);
}

// ft_factory manage : sending all the index of the file read
//					   monitor which keys are pressed until the window is terminated.
void			ft_factory(t_param **mlx)
{
	t_coord		pos;
	int			i;
	int			j;

	i = 0;
	j = 0;
	init_struct_coord(&pos);
	while (i < (*mlx)->nline)
	{
		j = 0;
		while (j < (*mlx)->ncol)
		{
			set_pos(i, j, mlx, &pos);
			j++;
		}
		i++;
	}
	view_usage(2, mlx);
	mlx_hook((*mlx)->win, 17, 17, cross_manager, mlx);
	mlx_key_hook((*mlx)->win, key_manager, mlx);
	mlx_loop((*mlx)->id);
}
