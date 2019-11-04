/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:56:19 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 16:56:21 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_htset(t_htab *tab, void *value, size_t size)
{
	uint32_t	i;
	void		*new_value;

	if (!tab || !value || !size)
		return (-1);
	i = 0;
	while (i < tab->size)
	{
		if (tab->items[i] != NULL && tab->items != DELETED_HI)
		{
			if (!(new_value = malloc(size)))
				return (-1);
			ft_memmove(new_value, value, size);
			tab->items[i]->value = new_value;
		}
		++i;
	}
	return (0);
}
