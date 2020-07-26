/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manya <manya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:27:22 by manya             #+#    #+#             */
/*   Updated: 2020/02/21 17:58:57 by manya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *source, int c, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	unsigned char	m;
	size_t			i;

	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)source;
	m = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
		if (str2[i - 1] == m)
			return (str1 + i);
	}
	return (NULL);
}
