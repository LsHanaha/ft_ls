/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:53:27 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 16:53:28 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_queue	*ft_qnew(t_list *elem)
{
	t_queue	*out;

	out = (t_queue *)malloc(sizeof(t_queue));
	if (!out)
		return (NULL);
	out->data = elem;
	out->last = elem;
	return (out);
}
