/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:55:07 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 16:55:09 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *lst, int (*f)(t_list *, void *), void *data)
{
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		if (f(lst, data))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
