/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphadd_uedge_id.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:01:19 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 17:01:21 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_graphadd_uedge_id(t_graph *g, uint32_t a, uint32_t b)
{
	ft_graphadd_edge_id(g, a, b);
	ft_graphadd_edge_id(g, b, a);
}
