/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qpush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:54:36 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 16:54:38 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_qpush(t_queue *q, t_list *elem)
{
	if (!q || !elem)
		return ;
	if (!q->last)
	{
		ft_lstadd(&q->data, elem);
		q->last = q->data;
	}
	else
		q->last = ft_lstappend(q->last, elem);
}
