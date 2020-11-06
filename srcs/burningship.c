/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:10:34 by fnancy            #+#    #+#             */
/*   Updated: 2020/11/06 18:02:08 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_burningship(t_str *str)
{
	double x,y, x0, y0;
	int iteration;
	double buf;

	y = 0;
	while (y < MAX_WIN_SIZE_Y)
	{
		x = 0;
		while (x < MAX_WIN_SIZE_X)
		{
			x0 = 0;
			y0 = 0;
			iteration = -1;
			while ((x0 * x0 + y0 * y0) <= 200.0 && ++iteration < str->iteration)
			{
				buf = x0 * x0 - y0 * y0 + (x / str->zoom + str->shift_x);
				y0 = 2 * fabs(x0 * y0) + (y / str->zoom + str->shift_y);
				x0 = buf;
			}
			buf = (double)iteration - log2(log2((x0 * x0) + (y0 * y0))) + 9.0;
			str->img_data[(int)x + (int)y * MAX_WIN_SIZE_Y] = get_color(buf);
			x++;
		}
		y++;
	}
}
