/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:59:39 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 16:59:41 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_graph	*ft_graphnew(uint32_t size)
{
	return (ft_htnew(size, BASE_ASCII, ALTBASE_ASCII));
}
