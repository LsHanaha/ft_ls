/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varrset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:52:56 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 16:53:04 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Currently only assigning to values that already exist in the array
**	is supported.
*/

void	ft_varrset(t_varr *varr, size_t idx, void *content)
{
	t_list	*current;

	if (!varr || !content || idx >= varr->size)
		exit(1);
	current = varr->buf;
	while (idx >= VARR_BUF_SIZE)
	{
		current = current->next;
		idx -= VARR_BUF_SIZE;
	}
	ft_memmove((char *)current->content + (varr->elem_size * idx),
	content, varr->elem_size);
}
