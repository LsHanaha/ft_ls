/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 10:36:51 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 17:30:03 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_slice(char *src, size_t start, size_t stop)
{
	char	*output;
	int		slice_len;

	if (stop <= start)
	{
		ft_putstr_fd("ft_slice: Stop less than start\n", 2);
		return (NULL);
	}
	slice_len = stop - start;
	if ((int)ft_strlen(&src[start]) < slice_len)
	{
		ft_putstr_fd("ft_slice: Scr len are less than required\n", 2);
		return (NULL);
	}
	if (!(output = ft_strnew(slice_len + 1)))
		return (NULL);
	output = ft_memcpy(output, &src[start], slice_len);
	output[slice_len] = '\0';
	return (output);
}
