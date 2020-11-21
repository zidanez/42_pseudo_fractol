/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 12:33:59 by fnancy            #+#    #+#             */
/*   Updated: 2020/11/21 14:57:14 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		draw_fractal(t_str *new1)
{
	pthread_t	threads[10];
	t_str		fractols[10];
	int			i;

	i = -1;
	while (++i < 10)
	{
		fractols[i] = *new1;
		if (new1->type_fract == 1)
			if (pthread_create(&threads[i], NULL,
			(void *(*)(void *))draw_mondelbrode, (void *)&fractols[i]))
				exit(0);
		if (new1->type_fract == 2)
			if (pthread_create(&threads[i], NULL,
			(void *(*)(void *))draw_julia, (void *)&fractols[i]))
				exit(0);
		if (new1->type_fract == 3)
			if (pthread_create(&threads[i], NULL,
			(void *(*)(void *))draw_burningship, (void *)&fractols[i]))
				exit(0);
	}
	while (i-- > 0)
		if (pthread_join(threads[i], NULL))
			exit(0);
	mlx_put_image_to_window(new1->mlx_ptr, new1->win_ptr, new1->img, 0, 0);
}
