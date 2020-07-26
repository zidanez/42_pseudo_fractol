/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:38:32 by manya             #+#    #+#             */
/*   Updated: 2020/07/26 14:11:27 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
	
# define MAX_WIN_SIZE_X 1000
# define MAX_WIN_SIZE_Y 1000

#include "../minilibx/X11/mlx.h"
#include "../libft/libft.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct		s_str{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	int		*img_data;
	int		zoom;
	double	shift_x;
	double	shift_y;
	double	c_e;
	double	c_m;
	int		mous_x;
	int		mous_y;
	int		lock;
	int		iteration;
	int		type_fract;
}					t_str;



int		mouse_press(int button, int x, int y, t_str *p);
int		key_press(int button, t_str *p);

int		get_color(double buf);
void	init_str(t_str *str);
void 	draw_mondelbrode(t_str *str);
void 	draw_julia(t_str *str);

int		close_win(void *param);
void	draw_fractal(t_str *new1);
int		mouse_move(int x, int y, t_str *p);

void	draw_fractal(t_str *new1);
void	draw_burningship(t_str *str);
#endif