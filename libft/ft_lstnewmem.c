/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewmem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:55:00 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 16:55:02 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnewmem(size_t size)
{
	t_list	*out;

	out = (t_list *)malloc(sizeof(t_list));
	if (!out)
		return (NULL);
	if (!size)
	{
		out->content = NULL;
		out->content_size = 0;
	}
	else
	{
		out->content = ft_memalloc(size);
		if (!(out->content))
		{
			ft_lstdel(&out, &ft_delcontent);
			return (NULL);
		}
		out->content_size = size;
	}
	out->next = NULL;
	return (out);
}
