/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alpup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manya <manya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:42:02 by manya             #+#    #+#             */
/*   Updated: 2020/02/21 17:42:10 by manya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_alpup(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i == 0)
		return (0);
	while (str[i])
	{
		if (str[i] <= 'z' && str[i] >= 'a')
			str[i] -= 32;
		i++;
	}
	return (str);
}
