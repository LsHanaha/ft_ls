/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_custom.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <jrobin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:47:59 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/18 16:48:06 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Copies a string to the variable given and returns the string's length
*/

size_t	ft_strdup_custom(const char *s, char **dest)
{
	size_t	length;

	if (!s || !dest)
		return (0);
	length = ft_strlen(s);
	*dest = (char *)malloc(length + 1);
	if (!(*dest))
		return (0);
	ft_strcpy(*dest, s);
	return (length);
}
