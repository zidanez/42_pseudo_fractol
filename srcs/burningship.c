/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:10:34 by fnancy            #+#    #+#             */
/*   Updated: 2020/11/21 13:58:22 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_burningship(t_str *str)
{
	t_fract v;

	v.y = -1;
	while (++v.y < MAX_WIN_SIZE_Y)
	{
		v.x = -1;
		while (++v.x < MAX_WIN_SIZE_X)
		{
			v.x0 = 0;
			v.y0 = 0;
			v.iteration = -1;
			while ((v.x0 * v.x0 + v.y0 * v.y0)\
					<= 200.0 && ++v.iteration < str->iteration)
			{
				v.buf = v.x0 * v.x0 - v.y0 * v.y0\
							+ (v.x / str->zoom + str->shift_x);
				v.y0 = 2 * fabs(v.x0 * v.y0) + (v.y / str->zoom + str->shift_y);
				v.x0 = v.buf;
			}
			v.buf = (double)v.iteration - log2(log2((v.x0 * v.x0)\
							+ (v.y0 * v.y0))) + 9.0;
			str->img_data[(int)v.x +\
							(int)v.y * MAX_WIN_SIZE_Y] = get_color(v.buf);
		}
	}
}
