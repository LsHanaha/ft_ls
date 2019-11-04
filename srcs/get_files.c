/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <jrobin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:15:12 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/18 16:47:30 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		(*pick_cmp(t_flags *f))(void *, void *)
{
	if (f->s_big)
		return (f->r ? cmp_rsize : cmp_size);
	if (f->t)
		return (f->r ? cmp_rmtime : cmp_mtime);
	if (f->f)
		return (cmp_none);
	else
		return (f->r ? cmp_ralpha : cmp_alpha);
}

static void		fill_file(t_file *file, char *current, struct dirent *entry)
{
	char	*path;

	if (!file || !entry)
		exit(MAJOR_PROBLEM);
	file->length = ft_strdup_custom(entry->d_name, &file->name);
	if (!file->length)
		exit(MAJOR_PROBLEM);
	path = get_path(current, entry->d_name);
	if (lstat(path, &file->stat) == -1)
		ft_error(path);
	free(path);
}

static int		filter_hidden_files(t_flags *f, struct dirent *entry)
{
	if (f->a)
		return (0);
	if (f->a_big && ft_strcmp(entry->d_name, ".") &&\
	ft_strcmp(entry->d_name, ".."))
		return (0);
	return (entry->d_name[0] == '.');
}

t_bbox			*get_files(t_flags *f, char *current, DIR *dir_ptr)
{
	t_bbox			*files;
	t_list			*newlst;
	struct dirent	*entry;
	t_file			file;

	if (!(files = new_bbox()))
		return (NULL);
	errno = 0;
	while ((entry = readdir(dir_ptr)))
	{
		if (filter_hidden_files(f, entry))
			continue ;
		fill_file(&file, current, entry);
		if (!(newlst = ft_lstnew(&file, sizeof(t_file))))
			return (del_bbox(&files));
		ft_lstaddsorted(&files->files, newlst, pick_cmp(f));
		files->n_files++;
		if (file.length > files->longest_name)
			files->longest_name = file.length;
	}
	if (errno)
		ft_error(current);
	return (files);
}
