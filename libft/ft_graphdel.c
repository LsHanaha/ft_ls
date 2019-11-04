/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:01:03 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 17:01:05 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_graphdel(t_graph **g)
{
	uint32_t	i;
	t_list		*lst;

	if (!g || !(*g))
		return ;
	i = 0;
	while (i < (*g)->size)
	{
		if ((*g)->items[i] != NULL && (*g)->items[i] != DELETED_HI)
		{
			lst = (*g)->items[i]->value;
			ft_lstdel(&lst, ft_delcontent);
			(*g)->items[i]->value = NULL;
		}
		++i;
	}
	ft_htdel(g, ft_hildel);
}
