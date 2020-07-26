/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manya <manya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:27:22 by manya             #+#    #+#             */
/*   Updated: 2020/02/21 17:59:18 by manya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_pow(double num, int pow)
{
	double	res;
	int		n;

	res = 1;
	if (!pow || pow == 0)
		return (1);
	if (pow < 0)
	{
		n = -1;
		pow *= -1;
	}
	else
		n = 1;
	while (pow != 0)
	{
		res *= num;
		pow--;
	}
	if (n < 0)
		return (1 / res);
	else
		return (res);
}
