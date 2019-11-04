/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_comparisons_reversed.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:01:41 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/18 21:01:42 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	args_cmp_ralpha(void *a, void *b)
{
	int	files_first;

	files_first = args_cmp_files_first(a, b);
	if (files_first)
		return (files_first);
	return (cmp_ralpha(a, b));
}

int	args_cmp_rmtime(void *a, void *b)
{
	int	files_first;

	files_first = args_cmp_files_first(a, b);
	if (files_first)
		return (files_first);
	return (cmp_rmtime(a, b));
}

int	args_cmp_rsize(void *a, void *b)
{
	int	files_first;

	files_first = args_cmp_files_first(a, b);
	if (files_first)
		return (files_first);
	return (cmp_rsize(a, b));
}
