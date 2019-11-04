/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_l_params3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:55:09 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 21:36:40 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_print.h"

void	ft_add_fname(t_file *file, char ***output, int c_w[L_WIDTH])
{
	int		fname_len;

	output[L_ROW][7] = ft_strdup(file->name);
	fname_len = ft_strlen(output[L_ROW][7]);
	if (c_w[7] < fname_len)
		c_w[7] = fname_len + 1;
}

void	snoop_dog(char *path, t_file *file, char ***output, int c_w[L_WIDTH])
{
	char	buf[101];
	char	dog;
	char	*full;
	int		len_link;

	len_link = 0;
	output[L_ROW][1] = (char *)ft_strnew(12);
	full = get_path(path, file->name);
	if (listxattr((const char *)full, buf, sizeof(buf), XATTR_NOFOLLOW) > 0)
		dog = '@';
	else
		dog = 0;
	free(full);
	c_w[L_WIDTH - 1] = 1;
	if (!dog)
		return ;
	output[L_ROW][1][10] = dog;
	len_link = ft_strlen(output[L_ROW][1]);
	if (c_w[1] < len_link)
		c_w[1] = len_link + 1;
}

void	ft_add_link(t_file *file, char ***output, int c_w[L_WIDTH], char *path)
{
	char	*full;
	char	*link;
	int		len_link;

	full = get_path(path, file->name);
	link = (char *)ft_strnew(1024);
	readlink(full, link, 512);
	free(full);
	output[L_ROW][8] = link;
	len_link = ft_strlen(link);
	if (!len_link)
		return ;
	ft_memmove(&link[512], link, len_link);
	ft_memmove(link, " -> ", 4);
	ft_memcpy(&link[4], &link[512], len_link);
}

void	ft_print_l_and_clean(char ***out, t_bbox *files,
		int column_width[L_WIDTH])
{
	ft_print_l(out, files->n_files, column_width, files);
	ft_clean_l_output(out, files->n_files);
}
