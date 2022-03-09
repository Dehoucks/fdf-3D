/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdehouck <rdehouck@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:46:19 by robindehouc       #+#    #+#             */
/*   Updated: 2022/03/09 14:35:23 by rdehouck         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// Cross Manager : Detect when the window's cross is clicked. If it's clicked, the window is closed.
int					cross_manager(t_param **mlx)
{
	mlx_destroy_window((*mlx)->id, (*mlx)->win);
	ft_memdel((void**)mlx);
	ft_putendl("QUIT");
	exit(EXIT_SUCCESS);
	return (0);
}
// Zoom out is limited to 0.01.
static void		zoom_out(t_param **mlx)
{
	(*mlx)->zoom -= 0.05;
	if ((*mlx)->zoom < 0.01)
		(*mlx)->zoom = 0.01;
}
// Move 10px in selected direction
static void		move(int keycode, t_param **mlx)
{
	if (keycode == 2)
		(*mlx)->shift_x += 10;
	if (keycode == 0)
		(*mlx)->shift_x -= 10;
	if (keycode == 1)
		(*mlx)->shift_y += 10;
	if (keycode == 13)
		(*mlx)->shift_y -= 10;
}

static void		color_switch(int keycode, t_param **mlx)
{
	if (keycode == 83)
		(*mlx)->color = 0xceff00;
	if (keycode == 84)
		(*mlx)->color = 0xFFFF00;
	if (keycode == 85)
		(*mlx)->color = 0x00FF00;
	if (keycode == 86)
		(*mlx)->color = 0x0000FF;
	if (keycode == 87)
		(*mlx)->color = 0xFF00FF;
	if (keycode == 88)
		(*mlx)->color = 0xFF0000;
	if (keycode == 89)
		(*mlx)->color = 0xFE6C9E;
	if (keycode == 91)
		(*mlx)->color = 0x24C8EC;
	if (keycode == 92)
		(*mlx)->color = 0xFFFFFF;
}

// Key Manager : Detect when a key is pressed and proceed to modificate the current window.
int				key_manager(int keycode, t_param **mlx)
{
	if (keycode == 69 || keycode == 24)
		(*mlx)->zoom += 0.02;
	if (keycode == 78 || keycode == 27)
		zoom_out(mlx);
	if (keycode == 53)
	{
		mlx_destroy_window((*mlx)->id, (*mlx)->win);
		ft_memdel((void**)mlx);
		ft_putendl("QUIT");
		exit(EXIT_SUCCESS);
	}
	if (keycode == 126)
		(*mlx)->alt += 5;
	if (keycode == 125)
		(*mlx)->alt -= 5;
	if (keycode >= 83 && keycode <= 92)
		color_switch(keycode, mlx);
	if (keycode >= 0 && keycode <= 13)
		move(keycode, mlx);
	mlx_clear_window((*mlx)->id, (*mlx)->win);
	ft_factory(mlx);
	return (0);
}
