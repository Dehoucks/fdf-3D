/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:46:36 by robindehouc       #+#    #+#             */
/*   Updated: 2022/02/17 22:46:38 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_pos(int i, int j, t_param **mlx, t_coord *pos)
{	
	// printf("i === %d // j === %d\n", i, j);
	// printf("i j = %d, i+1 j = %d, i j+1 = %d\n", (*mlx)->tab[i][j], (*mlx)->tab[i+1][j], (*mlx)->tab[i][j+1]);
	if (i < (*mlx)->nb_line - 1)
	{	
		pos->x1 = ((j - i) * 50 + 800) * (*mlx)->zoom + (*mlx)->shift_x;
		//printf("1 x1  %d - (%d;%d) == %d\n", pos->x1, i, j,(*mlx)->tab[i][j]);
		pos->y1 = ((j + i) * 10 + 300 - (*mlx)->tab[i][j] * (*mlx)->alt) *
			(*mlx)->zoom + (*mlx)->shift_y;
		//printf("1 y1  %d - (%d;%d) == %d\n", pos->y1, i, j,(*mlx)->tab[i][j]);
		pos->x2 = ((j - (i + 1)) * 50 + 800) * (*mlx)->zoom + (*mlx)->shift_x;
		//printf("1 x2  %d - (%d;%d) == %d\n", pos->x2, i, j,(*mlx)->tab[i][j]);
		pos->y2 = ((j + (i + 1)) * 10 + 300 - (*mlx)->tab[i + 1][j] *
				(*mlx)->alt) * (*mlx)->zoom + (*mlx)->shift_y;
		//printf("1 y2  %d - (%d;%d) == %d\n", pos->y2, i, j,(*mlx)->tab[i][j]);
		draw(&pos, mlx);
	}
	if (j < (*mlx)->nb_col - 1)
	{
		pos->x1 = ((j - i) * 50 + 800) * (*mlx)->zoom + (*mlx)->shift_x;
		//printf("2 x1  %d - (%d;%d) == %d\n", pos->x1, i, j,(*mlx)->tab[i][j]);
		pos->y1 = ((j + i) * 10 + 300 - (*mlx)->tab[i][j] *
				(*mlx)->alt) * (*mlx)->zoom + (*mlx)->shift_y;
		//printf("2 y1  %d - (%d;%d) == %d\n", pos->y1, i, j,(*mlx)->tab[i][j]);
		pos->x2 = (((j + 1) - i) * 50 + 800) * (*mlx)->zoom + (*mlx)->shift_x;
		//printf("2 x2  %d - (%d;%d) == %d\n", pos->x2, i, j,(*mlx)->tab[i][j]);
		pos->y2 = (((j + 1) + i) * 10 + 300 - (*mlx)->tab[i][j + 1] *
				(*mlx)->alt) * (*mlx)->zoom + (*mlx)->shift_y;
		//printf("2 y2  %d - (%d;%d) == %d\n", pos->y2, i, j,(*mlx)->tab[i][j]);
		draw(&pos, mlx);
	}
}

void	init_mlx(t_param **mlx)
{
	if (!((*mlx)->id = mlx_init()))
	{
		ft_putendl("_INIT_ERROR_");
		exit(EXIT_FAILURE);
	}
	(*mlx)->win = mlx_new_window((*mlx)->id, (*mlx)->height, (*mlx)->width,
			"FdF");
}

void	view_usage(int value, t_param **mlx)
{
	if (value == 1)
	{
		ft_putendl("Invalid format : type ./fdf [filename]");
		exit(EXIT_FAILURE);
	}
	if (value == 2)
	{
		mlx_string_put((*mlx)->id, (*mlx)->win, 5, 5, 0x00FF00,
				"**************************************");
		mlx_string_put((*mlx)->id, (*mlx)->win, 15, 25, 0x00FF00,
				"Zoom avant / arriere: + / -");
		mlx_string_put((*mlx)->id, (*mlx)->win, 15, 45, 0x00FF00,
				"Deplacement: Touches A - W - S - D");
		mlx_string_put((*mlx)->id, (*mlx)->win, 15, 65, 0x00FF00,
				"Augmenter altitude: Fleche-haut");
		mlx_string_put((*mlx)->id, (*mlx)->win, 15, 85, 0x00FF00,
				"Diminuer altitude: Fleche-bas");
		mlx_string_put((*mlx)->id, (*mlx)->win, 15, 105, 0x00FF00,
				"Changer couleur: Num. Pad de 1 a 9 ");
		mlx_string_put((*mlx)->id, (*mlx)->win, 15, 125, 0x00FF00,
				"Quitter: ESC");
		mlx_string_put((*mlx)->id, (*mlx)->win, 5, 145, 0x00FF00,
				"**************************************");
	}
}

void	view_int_tab(int **tab, int raw, int column)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < raw)
	{
		j = 0;
		while (j < column)
		{
			ft_putnbr(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	verif_content(void *var)
{
	if (var == NULL)
	{
		ft_putendl("MEMORY ALLOCATION ERROR");
		exit(EXIT_FAILURE);
	}
}
