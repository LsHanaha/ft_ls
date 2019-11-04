/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparisons_reversed.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:01:28 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/18 21:01:29 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	cmp_ralpha(void *a, void *b)
{
	return (cmp_alpha(a, b) * -1);
}

int	cmp_rmtime(void *a, void *b)
{
	return (cmp_mtime(a, b) * -1);
}

int	cmp_rsize(void *a, void *b)
{
	return (cmp_size(a, b) * -1);
}
