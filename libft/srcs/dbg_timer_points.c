/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_timer_points.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 09:50:58 by fnancy            #+#    #+#             */
/*   Updated: 2019/12/05 19:42:39 by fnancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbg_tools.h"

t_time				dbg_timer_point_ns(void)
{
	t_tspec			chp_tsp;

	if (dbg_timer_checkp(&chp_tsp) < 0)
		return (-1);
	return (DBG_TIME_NSEC_TO_UL((&chp_tsp)));
}

t_time				dbg_timer_point_ms(void)
{
	t_tspec			chp_tsp;

	if (dbg_timer_checkp(&chp_tsp) < 0)
		return (-1);
	return (DBG_TIME_MLSEC_TO_UL((&chp_tsp)));
}

t_time				dbg_timer_point_mks(void)
{
	t_tspec			chp_tsp;

	if (dbg_timer_checkp(&chp_tsp) < 0)
		return (-1);
	return (DBG_TIME_MKSEC_TO_UL((&chp_tsp)));
}

t_time				dbg_timer_point(void)
{
	t_tspec			chp_tsp;

	if (dbg_timer_checkp(&chp_tsp) < 0)
		return (-1);
	return (DBG_TIME_SEC_TO_UL((&chp_tsp)));
}
