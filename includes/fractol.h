/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:02:33 by fnancy            #+#    #+#             */
/*   Updated: 2020/11/21 16:02:36 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define MAX_WIN_SIZE_X 1000
# define MAX_WIN_SIZE_Y 1000

# include "../minilibx/X11/mlx.h"
# include "../Libft/includes/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct		s_color{
	int		color;
	int		r;
	int		g;
	int		b;
	double	hx;
	double	hy;
	double	hz;
}					t_color;

typedef struct		s_fract{
	double	x;
	double	y;
	double	x0;
	double	y0;
	int		iteration;
	double	buf;
}					t_fract;

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

int					mouse_press(int button, int x, int y, t_str *p);
int					key_press(int button, t_str *p);

int					get_color(double buf);
void				init_str(t_str *str);
void				draw_mondelbrode(t_str *str);
void				draw_julia(t_str *str);

int					close_win(void *param);
void				draw_fractal(t_str *new1);
int					mouse_move(int x, int y, t_str *p);

void				draw_burningship(t_str *str);
#endif
