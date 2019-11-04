/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_bbox.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:15:13 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/08 18:20:27 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_bbox	*new_bbox(void)
{
	t_bbox *out;

	if (!(out = (t_bbox *)malloc(sizeof(t_bbox))))
		return (NULL);
	out->files = NULL;
	out->n_files = 0;
	out->longest_name = 0;
	out->one_file = 0;
	return (out);
}
