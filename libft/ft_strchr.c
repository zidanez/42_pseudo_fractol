/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manya <manya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:27:22 by manya             #+#    #+#             */
/*   Updated: 2020/02/21 18:00:26 by manya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strchr(const char *str, int ch)
{
	unsigned char	k;
	char			*new;

	k = (unsigned char)ch;
	new = (char *)str;
	while (*new)
	{
		if (*new == ch)
			return (new);
		else
			new++;
	}
	if (k == '\0')
		return (new);
	else
		return (NULL);
}
