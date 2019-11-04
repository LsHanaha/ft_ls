/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htget.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:59:06 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 16:59:08 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_htget(t_htab *table, void const *key, size_t ksize,
		size_t *vsize)
{
	int64_t	id;

	id = ft_htgetid(table, key, ksize);
	if (id < 0)
		return (NULL);
	if (vsize)
		*vsize = table->items[id]->vsize;
	return (table->items[id]->value);
}
