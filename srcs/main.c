/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:44:04 by manya             #+#    #+#             */
/*   Updated: 2020/07/26 13:38:24 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


int		get_color(double buf)
{
	int color = 666;
	int r = (color >> 16) & 0xFF;
	int	g = (color >> 8) & 0xFF;
	int	b = color & 0xFF;
 	double hx = 0.5 + 0.5 * cos(0.5 * buf + (3.0 * color));
 	double hy = 0.5 + 0.5 * cos(0.5 * buf + (15.6 * color / 2));
 	double hz = 0.5 + 0.5 * cos(0.5 * buf + (5.6 * (-color)));

	r = (unsigned int) ((double) hx * 255) | r;
	g = (unsigned int) ((double) hy * 255) | g;
	b = (unsigned char) ((double) hz * 255) | b;
	return(r << 16 | g << 8 | b);
}

int		close_win(void *param)
{
	exit(0);
	return (0);
}


int main(int argc, char **argv)
{
	t_str	str;
	
	init_str(&str);
	if (ft_strequ(argv[1], "mondelbrot"))
		str.type_fract = 1;
	else if (ft_strequ(argv[1], "julia"))
		str.type_fract = 2;
	else
		exit (0);
	if (str.type_fract == 1)
	{
		str.shift_x = -2.6;
		str.shift_y = -2.0;
	}
	else if (str.type_fract == 2)
	{
		str.shift_x = 0;
		str.shift_y = 0;
	}
	draw_fractal(&str);
	mlx_put_image_to_window(str.mlx_ptr, str.win_ptr, str.img, 0, 0);
	mlx_hook(str.win_ptr, 17, 1L << 17, close_win, (void *)0);
	mlx_hook(str.win_ptr, 2, 1L << 17, key_press, &str);
	mlx_hook(str.win_ptr, 4, 1L << 17, mouse_press, &str);
	mlx_hook(str.win_ptr, 6, 0, mouse_move, &str);
	mlx_loop(str.mlx_ptr);
	return (0);
}
