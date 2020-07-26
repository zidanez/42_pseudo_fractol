/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:13:08 by manya             #+#    #+#             */
/*   Updated: 2020/07/26 13:36:20 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


int		mouse_move(int x, int y, t_str *p)
{
	if (p->type_fract == 2)
	{
		if (!(p->mous_x) && !(p->mous_y))
		{
			p->mous_x = x;
			p->mous_y = y;
		}
			p->c_e += (x - p->mous_x) / p->zoom;
			p->c_m += (y - p->mous_y) / p->zoom;
			p->mous_x = x;
			p->mous_y = y;
			draw_fractal(p);
	}
	return (0);
}


int		mouse_press(int button, int x, int y, t_str *p)
{
	double a[2];
	double a1;
	double b1;

	a[0] = (double)x / p->zoom + p->shift_x;
	a[1] = (double)y / p->zoom + p->shift_y;
	if (button == 4)
	{
		p->shift_x = a[0] - ((double)x / (p->zoom * 1.5));
		p->shift_y = a[1] - ((double)y / (p->zoom * 1.5));
		p->zoom *= 1.5;
		p->iteration += 10;
	}
	if (button == 5)
	{
		p->shift_x = a[0] - ((double)x / (p->zoom / 1.5));
		p->shift_y = a[1] - ((double)y / (p->zoom / 1.5));
		p->zoom /= 1.5;
		p->iteration -= 10;
	}
	draw_fractal(p);
	return (0);
}


int		key_press(int button, t_str *p)
{
	if (button == 53)
		close_win((void *)0);
	return (0);
}