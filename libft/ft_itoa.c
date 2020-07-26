/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manya <manya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:27:22 by manya             #+#    #+#             */
/*   Updated: 2020/02/21 17:58:19 by manya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_itoa(int n)
{
	size_t			i;
	char			*str;
	unsigned int	ncp;
	int				c;

	i = 1;
	c = n;
	while (c /= 10)
		i++;
	ncp = n;
	if (n < 0)
	{
		ncp = -n;
		i++;
	}
	if (!(str = ft_strnew(i)))
		return (NULL);
	str[--i] = ncp % 10 + '0';
	while (ncp /= 10)
		str[--i] = ncp % 10 + '0';
	if (n < 0)
		*(str) = '-';
	return (str);
}
