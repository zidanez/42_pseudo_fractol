/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:23:55 by fnancy            #+#    #+#             */
/*   Updated: 2020/11/21 14:31:35 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		vars_init(t_fract *v, t_str *str)
{
	v->iteration = 0;
	v->y = (double)MAX_WIN_SIZE_Y / str->zoom / 2 - str->shift_y;
}

void		vars_init_x0y0(t_fract *v, t_str *str)
{
	v->y0 = (double)v->y / str->zoom + str->shift_y - 2.0;
	v->x0 = (double)v->x / str->zoom - 3.0 / 2 + str->shift_x - 1.2;
}

void		draw_julia(t_str *str)
{
	t_fract v;

	vars_init(&v, str);
	while (v.y < MAX_WIN_SIZE_Y)
	{
		v.x = (double)MAX_WIN_SIZE_X / str->zoom / 2 - str->shift_x;
		while (v.x < MAX_WIN_SIZE_X)
		{
			vars_init_x0y0(&v, str);
			while ((v.x0 * v.x0 + v.y0 * v.y0)\
						<= 200.0 && v.iteration++ < str->iteration)
			{
				v.buf = v.x0 * v.x0 - v.y0 * v.y0;
				v.y0 = 2 * v.x0 * v.y0 + str->c_e;
				v.x0 = v.buf + str->c_m;
			}
			v.buf = (double)v.iteration - log2(log2((v.x0 * v.x0)\
						+ (v.y0 * v.y0))) + 9.0;
			str->img_data[(int)v.x +\
							(int)v.y * MAX_WIN_SIZE_X] = get_color(v.buf);
			v.iteration = 0;
			v.x++;
		}
		v.y++;
	}
}
