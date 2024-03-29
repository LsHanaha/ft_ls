/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:58:51 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 16:59:28 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint32_t	ft_hashget(void const *key, size_t ksize,
					t_hash_collision_info *info, uint32_t tabsize)
{
	uint32_t ahash;
	uint32_t bhash;

	ahash = ft_hash(key, ksize, info->base, tabsize);
	bhash = ft_hash(key, ksize, info->altbase, tabsize);
	if (!bhash)
		++bhash;
	return ((ahash + info->attempt * bhash) % tabsize);
}
