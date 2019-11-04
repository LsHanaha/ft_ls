/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hidel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:58:46 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 16:58:47 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hidel(t_hash_item **item)
{
	if (!item || !(*item) || *item == DELETED_HI)
		return ;
	if ((*item)->key)
		free((*item)->key);
	if ((*item)->value)
		free((*item)->value);
	free(*item);
	*item = DELETED_HI;
}
