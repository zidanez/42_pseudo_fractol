/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:24:12 by fnancy            #+#    #+#             */
/*   Updated: 2020/11/21 14:51:07 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		init_vars_x0y0(t_fract *v, t_str *str)
{
	v->x0 = 0;
	v->y0 = 0;
	v->iteration = -1;
}

void		draw_mondelbrode(t_str *str)
{
	t_fract v;

	v.y = -1;
	while (++v.y < MAX_WIN_SIZE_Y)
	{
		v.x = -1;
		while (++v.x < MAX_WIN_SIZE_X)
		{
			init_vars_x0y0(&v, str);
			while ((v.x0 * v.x0 + v.y0 * v.y0) <= 200.0 &&\
					++v.iteration < str->iteration)
			{
				v.buf = v.x0;
				v.x0 = (double)(v.x0 * v.x0 - v.y0 * v.y0) +\
						(v.x / str->zoom + str->shift_x);
				v.y0 = (double)2 * v.y0 * v.buf + (v.y / str->zoom\
							+ str->shift_y);
			}
			v.buf = (double)v.iteration - log2(log2((v.x0 * v.x0) +\
						(v.y0 * v.y0))) + 9.0;
			str->img_data[(int)v.x +\
						(int)v.y * MAX_WIN_SIZE_Y] = get_color(v.buf);
		}
	}
}
