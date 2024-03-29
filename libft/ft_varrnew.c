/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:52:43 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 16:52:44 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_varr	*ft_varrnew(size_t elem_size)
{
	t_varr	*out;

	if (!elem_size)
		return (NULL);
	out = (t_varr *)malloc(sizeof(t_varr));
	if (!out)
		return (NULL);
	out->buf = ft_lstnewmem(elem_size * VARR_BUF_SIZE);
	if (!out->buf)
	{
		free(out);
		return (NULL);
	}
	out->elem_size = elem_size;
	out->size = 0;
	return (out);
}
