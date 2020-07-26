/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manya <manya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:27:22 by manya             #+#    #+#             */
/*   Updated: 2020/02/21 18:02:43 by manya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *str1, const char *str2)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char *)str1;
	if (*str2 == '\0')
		return ((char *)str1);
	while (*str1)
	{
		while (str2[i] == str1[i])
		{
			i++;
			if (str2[i] == '\0')
			{
				ret = (char *)str1;
				return (ret);
			}
		}
		str1++;
		i = 0;
	}
	return (NULL);
}
