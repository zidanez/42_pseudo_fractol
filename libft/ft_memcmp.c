/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manya <manya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:27:22 by manya             #+#    #+#             */
/*   Updated: 2020/02/21 17:59:03 by manya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	if ((!arr1 && !arr2) || !n)
		return (0);
	i = 0;
	s1 = (unsigned char *)arr1;
	s2 = (unsigned char *)arr2;
	while (s1[i] == s2[i] && i < n)
	{
		i++;
		if (i == n)
			return (0);
	}
	return (s1[i] - s2[i]);
}
