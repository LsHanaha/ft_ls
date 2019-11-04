/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varrdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:53:13 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 16:53:16 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_varrdel(t_varr **varr)
{
	if (!varr || !(*varr))
		return ;
	if ((*varr)->buf)
		ft_lstdel(&(*varr)->buf, ft_delcontent);
	free(*varr);
	*varr = NULL;
}
