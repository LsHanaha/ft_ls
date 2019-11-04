/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_print.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:21:05 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 21:34:45 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_PRINT_H
# define FT_LS_PRINT_H

# include "ft_ls.h"
# include <unistd.h>
# include <fcntl.h>
# include <err.h>
# include <time.h>
# include <pwd.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <sys/types.h>
# include <sys/acl.h>
# include <sys/xattr.h>

typedef struct	s_protmode
{
	unsigned int	is_link : 1;
	unsigned int	is_reg : 1;
	unsigned int	is_dir : 1;
	unsigned int	is_chr : 1;
	unsigned int	is_blk : 1;
	unsigned int	is_fifo : 1;
	unsigned int	is_sock : 1;
	unsigned int	u_mask : 9;
	unsigned int	g_mask : 6;
	unsigned int	o_mask : 3;
}				t_protmode;

# define FLAG_ONE       (f->one)
# define FLAG_A         (f->A)
# define FLAG_R         (f->R)
# define FLAG_LIL_A     (f->a)
# define FLAG_H         (f->h)
# define FLAG_I         (f->i)
# define FLAG_L         (f->l)

# define LENGTH         (term_data[0])
# define WIDTH          (term_data[1])
# define HEIGHT         (term_data[2])

# define FILENAME		(file->name)
# define WORD_COUNT		(int)(files->n_files)
# define ROW			shape[0]
# define COLUMN			shape[1]

# define STAT			file->stat

# define L_WIDTH		13
# define L_ROW			c_w[L_WIDTH - 4]
# define L_COL			c_w[L_WIDTH - 3]

char			***ft_create_output_string(int term_data[3]);
void			ft_clean_output_string(char ***output_string, int term_data[3]);

void			ft_set_col_count(int term_size, t_bbox *files, t_flags *f,
		int term_data[3]);
void			ft_fill_row_output(char ***output_string, int shape[2],
		t_file *file, t_flags *f);
void			ft_print_columns(char ***output_string, int term_data[3],
		int word_count);
void			ft_iterate_for_column(t_list *list_of_files, int term_data[3],
		char ***output_string, t_flags *f);
void			ft_columns(t_flags *f, t_bbox *files, int term_size);
void			ft_print_l_and_clean(char ***out, t_bbox *files,
		int column_width[L_WIDTH]);
void			ft_clean_l_output(char ***output_string, int str_count);
char			***ft_create_l_output(int str_count);
void			ft_print_l(char ***out_str, int str_count,
		int col_width[L_WIDTH], t_bbox *b);
void			ft_print_one(t_file *file, t_flags *f);
void			ft_add_inode(t_flags *f, t_file *file, char ***out,
		int c_w[L_WIDTH]);
void			ft_add_pmode(t_file *file, char ***out,
		int c_w[L_WIDTH]);
void			ft_add_nlink(t_file *file, char ***out,
		int c_w[L_WIDTH]);
void			ft_add_uname(t_file *file, char ***out,
		int c_w[L_WIDTH]);
void			ft_add_group(t_file *file, char ***out, int c_w[L_WIDTH]);
void			ft_add_size(t_flags *f, t_file *file, char ***out,
		int c_w[L_WIDTH]);
void			ft_add_date(t_file *file, char ***out,
		int c_w[L_WIDTH]);
void			ft_add_fname(t_file *file, char ***out,
		int c_w[L_WIDTH]);
char			*ft_slice(char *src, size_t start, size_t stop);
void			ft_add_link(t_file *file, char ***output, int c_w[L_WIDTH],
		char *path);
void			snoop_dog(char *path, t_file *file, char ***output,
		int c_w[L_WIDTH]);

#endif
