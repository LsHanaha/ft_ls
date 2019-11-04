/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_cmp_files_first.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:52:37 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 16:52:38 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	args_cmp_files_first(void *a, void *b)
{
	return (S_ISDIR(((t_file *)a)->stat.st_mode)
			- S_ISDIR(((t_file *)b)->stat.st_mode));
}
