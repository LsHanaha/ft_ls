/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparisons.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:15:12 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/08 18:18:35 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	The lib function used for inserting in a sorted list puts the new same
**	objects to the left (does not preserve the original order)
*/

int	cmp_alpha(void *a, void *b)
{
	return (strcoll(((t_file *)a)->name,
			((t_file *)b)->name));
}

/*
**	Longs are needed to avoid overflow (both operands are longs)
*/

/*
**	-t needs newest first, so the order is flipped (last but one line)
*/

int	cmp_mtime(void *a, void *b)
{
	struct timespec	ta;
	struct timespec	tb;
	long			res;

	ta = ((t_file *)a)->stat.MTIME;
	tb = ((t_file *)b)->stat.MTIME;
	res = ((ta.tv_sec == tb.tv_sec) ?
		(ta.tv_nsec - tb.tv_nsec) : (ta.tv_sec - tb.tv_sec));
	if (res)
		return (res > 0 ? -1 : 1);
	return (cmp_alpha(a, b));
}

/*
**	Always returning as if b was bigger than a
**	to mimic the system function behaviour
*/

int	cmp_none(void *a, void *b)
{
	(void)a;
	(void)b;
	return (1);
}

/*
**	Again, the order is flipped (the last but one line)
*/

int	cmp_size(void *a, void *b)
{
	long	res;

	res = ((t_file *)a)->stat.st_size - ((t_file *)b)->stat.st_size;
	if (res)
		return (res > 0 ? -1 : 1);
	return (0);
}
