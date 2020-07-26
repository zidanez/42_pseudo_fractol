/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:03:27 by manya             #+#    #+#             */
/*   Updated: 2020/07/26 13:39:55 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fractol.h"

void draw_julia(t_str *str)
{
	double x,y, x0, y0;
	int iteration;
	double buf;

	iteration = 0;
	y = (double)MAX_WIN_SIZE_Y / str->zoom / 2 - str->shift_y;
	while(y < MAX_WIN_SIZE_Y)
	{
		x = (double)MAX_WIN_SIZE_X / str->zoom / 2 - str->shift_x;
		while(x < MAX_WIN_SIZE_X)
		{
			y0 = (double) y / str->zoom + str->shift_y - 2.0;                                                   
			x0 = (double) x / str->zoom - 3.0 / 2 + str->shift_x - 1.2;  
			while((x0 * x0 + y0 * y0) <= 200.0 && iteration++ < str->iteration)
			{
				buf = x0 * x0 - y0 * y0;                                                                           
				y0 = 2 * x0 * y0 + str->c_e;                                                                           
				x0 = buf + str->c_m;                                                                                 
			}
			buf = (double)iteration - log2(log2((x0 * x0) + (y0 * y0))) + 9.0;
			str->img_data[(int)x + (int)y * MAX_WIN_SIZE_X] = get_color(buf);
			iteration = 0;
			x++;
		}
		y++;
	}
}
