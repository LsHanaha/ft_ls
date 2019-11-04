/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hinew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:58:01 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 16:58:03 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_hash_item	*ft_hinew
	(void const *key, size_t ksize, void const *value, size_t vsize)
{
	t_hash_item	*out;

	if (!key || !ksize || !value || !vsize)
		return (NULL);
	out = (t_hash_item *)malloc(sizeof(t_hash_item));
	if (!out)
		return (NULL);
	out->key = malloc(ksize);
	out->value = malloc(vsize);
	if (!out->key || !out->value)
	{
		free(out);
		return (NULL);
	}
	ft_memmove(out->key, key, ksize);
	ft_memmove(out->value, value, vsize);
	out->ksize = ksize;
	out->vsize = vsize;
	return (out);
}
