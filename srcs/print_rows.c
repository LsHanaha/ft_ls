/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:41:27 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 21:46:02 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_print.h"

void	ft_print_one(t_file *file, t_flags *f)
{
	if (FLAG_I)
	{
		ft_putnbr((int)(file->stat.st_ino));
		ft_putchar(' ');
	}
	ft_putendl(file->name);
}

void	ft_print_total(int c_w[L_WIDTH], t_bbox *box)
{
	if (!L_ROW || box->one_file)
		return ;
	ft_putstr("total ");
	ft_putnbr((int)(c_w[L_WIDTH - 2]));
	ft_putchar('\n');
}

void	ft_print_space(char *row)
{
	int		col_len;

	col_len = ft_strlen(row);
	if (col_len == 10)
		ft_putchar(' ');
}

void	ft_print_l(char ***out_str, int str_count, int c_w[L_WIDTH], t_bbox *b)
{
	int		col;
	int		diff;
	int		row;

	col = -1;
	row = -1;
	ft_print_total(c_w, b);
	while (++row < str_count)
	{
		while (++col < (L_WIDTH - 4))
		{
			diff = c_w[col] - ft_strlen(out_str[row][col]);
			if (diff == c_w[col])
				continue;
			while (col > 0 && col <= 6 && !(!c_w[0] && col == 1) && diff-- > 0)
				ft_putchar(' ');
			if (col == 7)
				ft_putchar(' ');
			ft_putstr(out_str[row][col]);
			if (col == 1 && c_w[L_WIDTH - 1])
				ft_print_space(out_str[row][col]);
		}
		col = -1;
		ft_putchar('\n');
	}
}
