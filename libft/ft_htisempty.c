/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htisempty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:57:45 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 16:57:49 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returns two different kinds of empty: -1 to signal the pointer is invalid
**	and 1 to signal there are no valid items
*/

int	ft_htisempty(t_htab *table)
{
	uint32_t	i;

	if (!table)
		return (-1);
	i = 0;
	while (i < table->size)
	{
		if (table->items[i] != NULL && table->items[i] != DELETED_HI)
			return (0);
		++i;
	}
	return (1);
}
