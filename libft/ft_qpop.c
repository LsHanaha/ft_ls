/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qpop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:53:32 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 16:53:34 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_qpop(t_queue *q)
{
	t_list	*out;

	if (!q || !q->data)
		return (NULL);
	out = q->data;
	if (q->last == out)
		q->last = NULL;
	q->data = q->data->next;
	out->next = NULL;
	return (out);
}
