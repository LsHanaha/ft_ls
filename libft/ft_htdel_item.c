/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htdel_item.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:59:12 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 17:00:02 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_htdel_item(t_htab *table, void *key, size_t ksize,
							void (*delfunc)(t_hash_item **))
{
	int64_t	id;

	if (!delfunc)
		return ;
	id = ft_htgetid(table, key, ksize);
	if (id < 0)
		return ;
	delfunc(&table->items[id]);
}
