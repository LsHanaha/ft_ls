/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <jrobin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:45:08 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/18 16:45:19 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Original ls sorts the command-line arguments.
**	Reproducing this functionality.
*/

static int		(*pick_args_cmp(t_flags *f))(void *, void *)
{
	if (f->s_big)
		return (f->r ? args_cmp_rsize : args_cmp_size);
	if (f->t)
		return (f->r ? args_cmp_rmtime : args_cmp_mtime);
	if (f->f)
		return (args_cmp_none);
	else
		return (f->r ? args_cmp_ralpha : args_cmp_alpha);
}

static t_list	*clean_and_return_null(t_list **alst)
{
	ft_lstdel(alst, del_lst_file);
	return (NULL);
}

static t_list	*new_elem(char *name, struct stat *statbuf)
{
	t_file	file;

	if (!name || !statbuf)
		return (NULL);
	file.length = ft_strdup_custom(name, &file.name);
	if (!file.length)
		exit(MAJOR_PROBLEM);
	file.stat = *statbuf;
	return (ft_lstnew(&file, sizeof(t_file)));
}

/*
**	Here, stat is used instead of lstat,
**	because symlinks are read when passed as args
**
**	However, in the presence of -l flag, lstat should be used.
*/

static int		(*stat_lstat(t_flags *f))(const char *, struct stat *)
{
	if (f->l)
		return (lstat);
	else
		return (stat);
}

t_list			*process_args(t_flags *f, int argc, char **argv, int i)
{
	t_list		*out;
	t_list		*lst;
	struct stat	statbuf;

	if (i == argc)
	{
		if (stat_lstat(f)(".", &statbuf) == -1)
			return (NULL);
		return (new_elem(".", &statbuf));
	}
	out = NULL;
	while (i < argc)
	{
		if (stat_lstat(f)(argv[i], &statbuf) == -1)
		{
			ft_error(argv[i]);
			++i;
			continue ;
		}
		if (!(lst = new_elem(argv[i], &statbuf)))
			return (clean_and_return_null(&out));
		ft_lstaddsorted(&out, lst, pick_args_cmp(f));
		++i;
	}
	return (out);
}
