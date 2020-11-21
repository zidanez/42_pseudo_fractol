/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:23:45 by fnancy            #+#    #+#             */
/*   Updated: 2020/11/21 13:23:50 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		init_str(t_str *str)
{
	int		bit_depth;
	int		line;
	int		endian;

	bit_depth = 32;
	line = MAX_WIN_SIZE_X;
	endian = 0;
	str->c_e = 0.32563;
	str->c_m = 0.3842;
	str->zoom = 200;
	str->mlx_ptr = mlx_init();
	str->win_ptr = mlx_new_window(str->mlx_ptr,\
						MAX_WIN_SIZE_X, MAX_WIN_SIZE_Y, "FRACTOL");
	str->img = mlx_new_image(str->mlx_ptr, MAX_WIN_SIZE_X, MAX_WIN_SIZE_Y);
	str->img_data = (int*)mlx_get_data_addr(str->img,\
							&bit_depth, &line, &endian);
	str->iteration = 50;
}
