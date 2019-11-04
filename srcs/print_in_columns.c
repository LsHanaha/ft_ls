/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_in_columns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 20:27:35 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 17:24:47 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_print.h"

void	ft_set_col_count(int term_size, t_bbox *files, t_flags *f,
int term_data[3])
{
	int		extension;
	int		word_len;
	double	word_count;
	double	height;

	extension = 0;
	word_len = (int)(files->longest_name) + 1;
	word_count = (int)(files->n_files);
	word_len += 9 ? (FLAG_I) : 0;
	if (!term_size)
		term_size = word_len;
	term_data[0] = word_len;
	term_data[1] = term_size / word_len;
	height = word_count / WIDTH;
	if (height - (int)(word_count / term_data[1]) > 0)
		extension = 1;
	term_data[2] = (int)word_count / term_data[1] + extension;
	if (WIDTH == 1 || WORD_COUNT == 1)
		FLAG_ONE = 1;
	return ;
}

void	ft_fill_row_output(char ***output_string, int shape[2], t_file *file,
t_flags *f)
{
	char	*string;
	int		str_len;

	if (FLAG_I)
	{
		string = ft_itoa((int)((file->stat).st_ino));
		str_len = ft_strlen(string);
		ft_memmove(output_string[ROW][COLUMN], string, str_len);
		output_string[ROW][COLUMN][str_len++] = ' ';
		ft_memmove(&output_string[ROW][COLUMN][str_len], FILENAME,
		ft_strlen(FILENAME));
		return ;
	}
	ft_memmove(output_string[ROW][COLUMN], FILENAME, ft_strlen(FILENAME));
}

void	ft_print_columns(char ***output_string, int term_data[3],
int word_count)
{
	int		i;
	int		j;
	int		w_c;
	int		length;

	i = -1;
	j = -1;
	w_c = 0;
	while (++i < HEIGHT)
	{
		while (++j < WIDTH)
		{
			length = LENGTH - ft_strlen(output_string[i][j]);
			if (length == LENGTH)
				break ;
			ft_putstr(output_string[i][j]);
			if (w_c++ == word_count - 1)
				return (ft_putchar('\n'));
			while (length-- > 0)
				ft_putchar(' ');
		}
		ft_putchar('\n');
		j = -1;
	}
}

void	ft_iterate_for_column(t_list *list_of_files, int term_data[3],
char ***output_string, t_flags *f)
{
	int				i;
	int				shape[2];
	t_file			*file;

	i = 0;
	ROW = 0;
	COLUMN = 0;
	while (list_of_files)
	{
		file = (t_file *)(list_of_files->content);
		ROW = ROW % HEIGHT;
		COLUMN = COLUMN % WIDTH;
		if ((!ROW || HEIGHT == 1) && i)
			COLUMN++;
		ft_fill_row_output(output_string, shape, file, f);
		list_of_files = list_of_files->next;
		i++;
		ROW++;
	}
}

void	ft_columns(t_flags *f, t_bbox *files, int term_size)
{
	int		term_data[3];
	char	***output_string;

	if (files->n_files == 0)
		return ;
	ft_set_col_count(term_size, files, f, term_data);
	if (FLAG_ONE)
		return ;
	output_string = ft_create_output_string(term_data);
	ft_iterate_for_column(files->files, term_data, output_string, f);
	ft_print_columns(output_string, term_data, files->n_files);
	ft_clean_output_string(output_string, term_data);
}
