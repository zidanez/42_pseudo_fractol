/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manya <manya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:27:22 by manya             #+#    #+#             */
/*   Updated: 2020/02/21 18:02:55 by manya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;

	if (*str2 == '\0')
		return ((char *)str1);
	i = 0;
	while (str1[i] != '\0' && i < len)
	{
		if (str1[i] == str2[0])
		{
			j = 1;
			while (str1[i + j] == str2[j] && str2[j] != '\0' && i + j < len)
			{
				j++;
			}
			if (str2[j] == '\0')
				return ((char *)(str1 + i));
		}
		i++;
	}
	return (NULL);
}
