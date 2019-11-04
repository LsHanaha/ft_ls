/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:01:33 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 17:01:35 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int64_t	ft_graphadd(t_graph *g, void const *key, size_t ksize)
{
	return (ft_htadd(g, ft_hilnew(key, ksize, NULL, sizeof(t_list))));
}
