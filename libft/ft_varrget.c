/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varrget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:54:07 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 16:54:08 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_varrget(t_varr *varr, size_t idx)
{
	t_list	*current;

	if (!varr || idx >= varr->size)
		exit(1);
	current = varr->buf;
	while (idx >= VARR_BUF_SIZE)
	{
		current = current->next;
		idx -= VARR_BUF_SIZE;
	}
	return ((char *)current->content + (varr->elem_size * idx));
}
