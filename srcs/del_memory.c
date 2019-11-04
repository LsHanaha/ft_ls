/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_bbox.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:15:12 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/08 18:15:12 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		del_lst_file(void **content, size_t *size)
{
	if (content && *content)
	{
		if (((t_file *)(*content))->name)
			free(((t_file *)(*content))->name);
		free(*content);
		*content = NULL;
	}
	if (size)
		*size = 0;
}

void		*del_bbox(t_bbox **box)
{
	if (!box || !(*box))
		return (NULL);
	ft_lstdel(&(*box)->files, del_lst_file);
	free(*box);
	*box = NULL;
	return (NULL);
}
