/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:15:13 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/08 18:20:15 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_path(char *path, char *filename)
{
	char	*out;

	out = (char *)malloc(ft_strlen(path) + ft_strlen(filename) + 2);
	ft_stpcpy(ft_stpcpy(ft_stpcpy(out, path), "/"), filename);
	return (out);
}
