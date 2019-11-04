/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_comparisons.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:52:06 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 16:52:07 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	args_cmp_alpha(void *a, void *b)
{
	int	files_first;

	files_first = args_cmp_files_first(a, b);
	if (files_first)
		return (files_first);
	return (cmp_alpha(a, b));
}

int	args_cmp_mtime(void *a, void *b)
{
	int	files_first;

	files_first = args_cmp_files_first(a, b);
	if (files_first)
		return (files_first);
	return (cmp_mtime(a, b));
}

int	args_cmp_none(void *a, void *b)
{
	int	files_first;

	files_first = args_cmp_files_first(a, b);
	if (files_first)
		return (files_first);
	return (cmp_none(a, b));
}

int	args_cmp_size(void *a, void *b)
{
	int	files_first;

	files_first = args_cmp_files_first(a, b);
	if (files_first)
		return (files_first);
	return (cmp_size(a, b));
}
