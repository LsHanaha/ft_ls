/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <jrobin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:15:12 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/18 16:47:50 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <unistd.h>

static void	recurse(t_flags *f, char *current, t_bbox *files)
{
	t_file	*file;
	t_list	*lst;
	char	*path;

	lst = files->files;
	while (lst)
	{
		file = lst->content;
		if (!(S_ISDIR(file->stat.st_mode)) || (f->a
				&& (!ft_strcmp(file->name, ".")
					|| !ft_strcmp(file->name, ".."))))
		{
			lst = lst->next;
			continue ;
		}
		path = get_path(current, file->name);
		write(1, "\n", 1);
		ft_putstr(path);
		write(1, ":\n", 2);
		ft_ls(f, path, file, PDN_NO);
		free(path);
		lst = lst->next;
	}
}

static void	deal_with_one_file(t_flags *f, t_file *file)
{
	t_bbox	*files;
	t_list	*lst;

	if (!(lst = ft_lstnew(&(t_file){ft_strdup(file->name),
			file->length, file->stat}, sizeof(t_file))))
		return (ft_error(file->name));
	if (!(files = new_bbox()))
	{
		free(((t_file *)lst->content)->name);
		ft_lstdel(&lst, ft_delcontent);
		return (ft_error(file->name));
	}
	files->n_files = 1;
	files->longest_name = ((t_file *)lst->content)->length;
	files->files = lst;
	files->one_file = 1;
	output(f, file->name, files);
	del_bbox(&files);
}

void		ft_ls(t_flags *f, char *current, t_file *file, int print_dir_name)
{
	DIR				*dir_ptr;
	t_bbox			*files;

	if (!(S_ISDIR(file->stat.st_mode)))
		return (deal_with_one_file(f, file));
	if (!(dir_ptr = opendir(current)))
		return (ft_error(current));
	if (!(files = get_files(f, current, dir_ptr)))
		return (ft_error(current));
	if (print_dir_name)
	{
		ft_putstr(current);
		write(1, ":\n", 2);
	}
	output(f, current, files);
	if (f->r_big)
		recurse(f, current, files);
	del_bbox(&files);
	closedir(dir_ptr);
}
