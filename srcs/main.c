/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:24:05 by fnancy            #+#    #+#             */
/*   Updated: 2020/11/21 15:33:25 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			get_color(double buf)
{
	t_color	c;

	c.color = 666;
	c.r = (c.color >> 16) & 0xFF;
	c.g = (c.color >> 8) & 0xFF;
	c.b = c.color & 0xFF;
	c.hx = 0.5 + 0.5 * cos(0.5 * buf + (3.0 * c.color));
	c.hy = 0.5 + 0.5 * cos(0.5 * buf + (15.6 * c.color / 2));
	c.hz = 0.5 + 0.5 * cos(0.5 * buf + (5.6 * (-c.color)));
	c.r = (unsigned int)((double)c.hx * 255) | c.r;
	c.g = (unsigned int)((double)c.hy * 255) | c.g;
	c.b = (unsigned char)((double)c.hz * 255) | c.b;
	return (c.r << 16 | c.g << 8 | c.b);
}

int			close_win(void *param)
{
	exit(0);
	return (0);
}

void		init_shifts(t_str *str)
{
	if (str->type_fract == 2)
	{
		str->shift_x = 0;
		str->shift_y = 0;
	}
	else
	{
		str->shift_x = -2.6;
		str->shift_y = -2.0;
	}
}

int			main(int argc, char **argv)
{
	t_str	str;

	init_str(&str);
	if (ft_strequ(argv[1], "mandelbrot"))
		str.type_fract = 1;
	else if (ft_strequ(argv[1], "julia"))
		str.type_fract = 2;
	else if (ft_strequ(argv[1], "burningship"))
		str.type_fract = 3;
	else
	{
		ft_putendl("Using: ./fractol [mandelbrot | julia | burningship]");
		exit(0);
	}
	init_shifts(&str);
	draw_fractal(&str);
	mlx_put_image_to_window(str.mlx_ptr, str.win_ptr, str.img, 0, 0);
	mlx_hook(str.win_ptr, 17, 1L << 17, close_win, (void *)0);
	mlx_hook(str.win_ptr, 2, 1L << 17, key_press, &str);
	mlx_hook(str.win_ptr, 4, 1L << 17, mouse_press, &str);
	mlx_hook(str.win_ptr, 6, 0, mouse_move, &str);
	mlx_loop(str.mlx_ptr);
	return (0);
}
