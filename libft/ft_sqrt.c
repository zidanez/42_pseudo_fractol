/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manya <manya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:27:22 by manya             #+#    #+#             */
/*   Updated: 2020/02/21 18:00:09 by manya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_sqrt(double num)
{
	double	r;
	double	q;
	int		i;

	q = 0;
	r = 1;
	i = 0;
	if (!num)
		return (0);
	while (i < 15)
	{
		q = 1 / ft_pow(10, i);
		while (((r + q) * (r + q)) < num)
			r += q;
		i++;
	}
	return (r);
}