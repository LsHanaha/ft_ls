/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:41:34 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 21:35:11 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_print.h"

int		ft_get_term_size(void)
{
	struct winsize	ws;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	return ((int)((&ws)->ws_col));
}

void	ft_create_l(t_flags *f, t_file *file, char ***output, int c_w[L_WIDTH])
{
	c_w[L_WIDTH - 2] += (int)(STAT.st_blocks);
	ft_add_inode(f, file, output, c_w);
	ft_add_pmode(file, output, c_w);
	ft_add_nlink(file, output, c_w);
	ft_add_uname(file, output, c_w);
	ft_add_group(file, output, c_w);
	ft_add_size(f, file, output, c_w);
	ft_add_date(file, output, c_w);
	ft_add_fname(file, output, c_w);
	L_ROW++;
}

void	ft_init_column_width(int column_width[L_WIDTH])
{
	int		i;

	i = 0;
	while (i < L_WIDTH)
		column_width[i++] = 0;
}

void	ft_rows(t_flags *f, t_bbox *files, char ***out, char *path)
{
	t_file	*file;
	t_list	*list_of_files;
	int		column_width[L_WIDTH];

	ft_init_column_width(column_width);
	if (FLAG_L)
		out = ft_create_l_output(files->n_files);
	list_of_files = files->files;
	while (list_of_files)
	{
		file = (t_file *)(list_of_files->content);
		if (FLAG_L)
		{
			snoop_dog(path, file, out, column_width);
			ft_add_link(file, out, column_width, path);
			ft_create_l(f, file, out, column_width);
		}
		else
			ft_print_one(file, f);
		list_of_files = list_of_files->next;
	}
	if (FLAG_L)
		ft_print_l_and_clean(out, files, column_width);
}

void	output(t_flags *f, char *current, t_bbox *files)
{
	static int		term_size;
	int				flag_one;
	int				word_printed;

	flag_one = FLAG_ONE;
	if (!term_size)
		term_size = ft_get_term_size();
	if (!FLAG_L && !FLAG_ONE)
		ft_columns(f, files, term_size);
	if (FLAG_L || FLAG_ONE)
		ft_rows(f, files, NULL, current);
	FLAG_ONE = flag_one;
	word_printed = 0;
}
