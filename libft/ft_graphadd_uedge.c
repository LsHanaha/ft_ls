/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphadd_uedge.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:59:34 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 16:59:36 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_graphadd_uedge(t_graph *g, t_obj *a, t_obj *b)
{
	int64_t	aid;
	int64_t	bid;

	if (!a || !b)
		return ;
	aid = ft_htgetid(g, a->data, a->size);
	if (aid < 0)
		return ;
	bid = ft_htgetid(g, b->data, b->size);
	if (bid < 0)
		return ;
	ft_graphadd_uedge_id(g, aid, bid);
}
