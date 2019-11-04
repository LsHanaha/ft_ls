/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_files_to_output.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <jrobin-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:45:34 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/18 16:47:11 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	init_regular_files(t_bbox *regular_files, t_list *current)
{
	regular_files->files = current;
	regular_files->n_files = 1;
	regular_files->longest_name = ((t_file *)current->content)->length;
}

/*
**	Joins all regular files into a bbox to output them all together
*/

t_list		*send_files_to_output(t_flags *f, t_list *current)
{
	t_bbox	*regular_files;
	t_list	*first_dir;

	if (!current || S_ISDIR(((t_file *)current->content)->stat.st_mode))
		return (current);
	if (!(regular_files = new_bbox()))
		exit(MAJOR_PROBLEM);
	init_regular_files(regular_files, current);
	while (current->next
			&& !S_ISDIR(((t_file *)current->next->content)->stat.st_mode))
	{
		current = current->next;
		++(regular_files->n_files);
		if (((t_file *)current->content)->length > regular_files->longest_name)
			regular_files->longest_name = ((t_file *)current->content)->length;
	}
	first_dir = current->next;
	current->next = NULL;
	regular_files->one_file = 1;
	output(f, ".", regular_files);
	current->next = first_dir;
	free(regular_files);
	if (first_dir)
		ft_putchar('\n');
	return (first_dir);
}
