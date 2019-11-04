/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:56:32 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 16:56:56 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uint32_t	ft_pow_(uint32_t n, size_t exp)
{
	uint32_t	out;

	out = 1;
	while (exp-- != 0)
		out *= n;
	return (out);
}

uint32_t		ft_hash(void const *key, size_t ksize, uint32_t base,\
uint32_t tabsize)
{
	uint32_t	out;
	size_t		i;

	out = 0;
	i = 0;
	while (i < ksize)
	{
		out += (ft_pow_(base, ksize - (i + 1)) * ((unsigned char *)key)[i]);
		++i;
	}
	return (out % tabsize);
}
