/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnelem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manya <manya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:27:22 by manya             #+#    #+#             */
/*   Updated: 2020/02/21 17:58:42 by manya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstnelem(t_list *lst, size_t s)
{
	size_t r;

	r = 0;
	while (s > (r - 1))
	{
		if (lst->next)
			return (NULL);
		lst = lst->next;
		r++;
	}
	return (lst);
}
