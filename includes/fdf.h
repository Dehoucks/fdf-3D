/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdehouck <rdehouck@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:32:22 by mtacnet           #+#    #+#             */
/*   Updated: 2022/02/18 16:05:45 by rdehouck         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"

typedef struct		s_coord
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
}					t_coord;

typedef struct		s_param
{
	int				**tab;
	int				height;
	int				width;
	int				alt;
	int				nline;
	int				ncol;
	int				color;
	int				shift_x;
	int				shift_y;
	void			*id;
	void			*win;
	float			zoom;
	t_coord			coord;
}					t_param;

int					check_map(char *argv, t_param **mlx);
int					key_manager(int keycode, t_param **mlx);
char				*map_to_string(char *map, t_param **mlx);
void				pixel_linker(t_coord **pos, t_param **mlx);
void				map_to_tab(t_param **mlx, char *map);
void				view_int_tab(int **tab, int raw, int column);
void				verif_content(void *var);
void				init_mlx(t_param **mlx);
void				set_pos(int i, int j, t_param **mlx, t_coord *pos);
void				view_usage(int value, t_param **mlx);
void				init_struct_mlx(t_param **mlx);
void				init_struct_coord(t_coord *pos);
void				init_mlx(t_param **mlx);
void				ft_factory(t_param **mlx);
void				ft_paint(t_param **mlx, int x, int y);
void				verif_fd(int fd);

#endif
