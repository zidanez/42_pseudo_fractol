/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manya <manya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:27:22 by manya             #+#    #+#             */
/*   Updated: 2020/02/21 17:58:49 by manya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_matdel(void **as, int i)
{
	if (!as || !*as)
		return ;
	while (i)
	{
		ft_memdel(&as[i]);
		as[i] = NULL;
		i--;
	}
	ft_memdel(as);
	as = NULL;
}