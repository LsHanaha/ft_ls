/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:57:26 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 16:57:28 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_htab	*ft_htnew(uint32_t size, uint32_t base, uint32_t altbase)
{
	t_htab	*out;

	if (!size)
		return (NULL);
	out = (t_htab *)malloc(sizeof(t_htab));
	if (!out)
		return (NULL);
	out->size = size;
	out->items = (t_hash_item **)ft_memalloc(sizeof(t_hash_item *) * size);
	if (!out->items)
	{
		free(out);
		return (NULL);
	}
	out->base = base;
	out->altbase = altbase;
	out->count = 0;
	return (out);
}
