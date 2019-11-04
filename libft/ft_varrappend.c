/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varrappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:52:48 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 16:52:49 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_varrappend(t_varr *varr, void *content)
{
	t_list	*last;
	t_list	*newlst;

	if (!varr || !content)
		return ;
	if (varr->size && varr->size % VARR_BUF_SIZE == 0)
	{
		newlst = ft_lstnewmem(varr->elem_size * VARR_BUF_SIZE);
		if (!newlst)
			exit(1);
		last = ft_lstappend(varr->buf, newlst);
	}
	else
	{
		last = varr->buf;
		while (last->next)
			last = last->next;
	}
	ft_memmove((char *)last->content +
			(varr->elem_size * (varr->size % VARR_BUF_SIZE)),
			content, varr->elem_size);
	++(varr->size);
}
