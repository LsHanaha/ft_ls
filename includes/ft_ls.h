/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 22:02:20 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/18 17:01:43 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

/*
**	INCLUDES ===================================================================
*/

# include "libft.h"
# include "sys/stat.h"
# include <errno.h>
# include <string.h>
# include <dirent.h>
# include <locale.h>
# include <sys/ioctl.h>

/*
**	CROSS PLATFORM SUPPORT =====================================================
*/

# ifdef __linux__
#  define MTIME st_mtim
# endif
# ifdef __APPLE__
#  define MTIME st_mtimespec
# endif

/*
**	DATA STRUCTURES ============================================================
*/

/*
**	Original ls has three exit codes
**	0 if everything's fine
**	1 if there's been a minor problem (like couldn't open a file). Usually if
**	you don't exit on error, it's a minor problem.
**	2 if there's been a major problem (like it couldn't parse the arguments).
**	Is usually followed by immediate program termination.
*/

enum			e_codes
{
	OK,
	MINOR_PROBLEM,
	MAJOR_PROBLEM
};

typedef struct	s_file
{
	char			*name;
	size_t			length;
	struct stat		stat;
}				t_file;

# define ALLOWED_OPTIONS "1ARSafhilrt"
# define USAGE_MESSAGE "usage: ft_ls [-"ALLOWED_OPTIONS"] [file ...]\n"

typedef struct	s_flags
{
	unsigned int	one : 1;
	unsigned int	a_big : 1;
	unsigned int	r_big : 1;
	unsigned int	s_big : 1;
	unsigned int	a : 1;
	unsigned int	f : 1;
	unsigned int	h : 1;
	unsigned int	i : 1;
	unsigned int	l : 1;
	unsigned int	r : 1;
	unsigned int	t : 1;
	unsigned int	print_dirs : 1;
}				t_flags;

/*
**	Building an abstraction level around how files are represented, so that it
**	is easier to switch to RBT if needed.
**
**	Black Box, Mr Druz. What's in it?
*/

typedef struct	s_bbox
{
	size_t			n_files;
	size_t			longest_name;
	t_list			*files;
	unsigned int	one_file : 1;
}				t_bbox;

enum			e_print_dir_names
{
	PDN_NO,
	PDN_YES
};

/*
**	PUBLIC FUNCTIONS ===========================================================
*/

void			ft_ls(t_flags *f, char *current, t_file *file,
		int print_dir_name);

void			ft_error(char *s);
size_t			ft_strdup_custom(const char *s, char **dest);
t_bbox			*get_files(t_flags *f, char *current, DIR *dir_ptr);
int				parse_args(t_flags *f, int argc, char **argv);
t_list			*process_args(t_flags *f, int argc, char **argv, int i);
t_list			*send_files_to_output(t_flags *f, t_list *current);
void			output(t_flags *f, char *current, t_bbox *files);

/*
**	A useful function to build a full path to a file.
*/

char			*get_path(char *path, char *filename);

/*
**	Data structures functions
*/

void			del_lst_file(void **content, size_t *size);
void			*del_bbox(t_bbox **box);
t_bbox			*new_bbox(void);

/*
**	COMPARISONS
*/

int				cmp_alpha(void *a, void *b);
int				cmp_mtime(void *a, void *b);
int				cmp_none(void *a, void *b);
int				cmp_size(void *a, void *b);

int				cmp_ralpha(void *a, void *b);
int				cmp_rmtime(void *a, void *b);
int				cmp_rsize(void *a, void *b);

int				args_cmp_files_first(void *a, void *b);

int				args_cmp_alpha(void *a, void *b);
int				args_cmp_mtime(void *a, void *b);
int				args_cmp_none(void *a, void *b);
int				args_cmp_size(void *a, void *b);

int				args_cmp_ralpha(void *a, void *b);
int				args_cmp_rmtime(void *a, void *b);
int				args_cmp_rsize(void *a, void *b);

/*
**	USER DEFINES ===============================================================
*/

#endif
