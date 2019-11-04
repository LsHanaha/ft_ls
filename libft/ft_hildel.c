/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hildel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:59:19 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 16:59:21 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hildel(t_hash_item **item)
{
	if (!item || !(*item) || *item == DELETED_HI)
		return ;
	if ((*item)->key)
		free((*item)->key);
	free(*item);
	*item = DELETED_HI;
}
