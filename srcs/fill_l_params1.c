/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_l_params1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:20:30 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 21:48:07 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_print.h"

void	ft_add_inode(t_flags *f, t_file *file, char ***output, int c_w[L_WIDTH])
{
	int		inode_len;
	char	*inode_str;

	if (!FLAG_I)
	{
		output[L_ROW][L_COL] = (char *)ft_strnew(1);
		return ;
	}
	inode_str = ft_itoa((int)(STAT.st_ino));
	output[L_ROW][L_COL] = inode_str;
	inode_len = ft_strlen(inode_str);
	if (c_w[0] < inode_len + 1)
		c_w[0] = inode_len + 2;
}

void	ft_pmode_acc(t_file *file, char ***output, int c_w[L_WIDTH])
{
	int		pmode_len;
	int		j;

	j = 1;
	output[L_ROW][1][j++] = (STAT.st_mode & S_IRUSR) ? 'r' : '-';
	output[L_ROW][1][j++] = (STAT.st_mode & S_IWUSR) ? 'w' : '-';
	output[L_ROW][1][j++] = (STAT.st_mode & S_IXUSR) ? 'x' : '-';
	output[L_ROW][1][j++] = (STAT.st_mode & S_IRGRP) ? 'r' : '-';
	output[L_ROW][1][j++] = (STAT.st_mode & S_IWGRP) ? 'w' : '-';
	output[L_ROW][1][j++] = (STAT.st_mode & S_IXGRP) ? 'x' : '-';
	output[L_ROW][1][j++] = (STAT.st_mode & S_IROTH) ? 'r' : '-';
	output[L_ROW][1][j++] = (STAT.st_mode & S_IWOTH) ? 'w' : '-';
	output[L_ROW][1][j++] = (STAT.st_mode & S_IXOTH) ? 'x' : '-';
	pmode_len = ft_strlen(output[L_ROW][1] + 1);
	if (c_w[1] < pmode_len)
		c_w[1] = pmode_len + 1;
}

void	ft_add_pmode(t_file *file, char ***output, int c_w[L_WIDTH])
{
	if (S_ISLNK(STAT.st_mode))
		output[L_ROW][1][0] = 'l';
	if (S_ISREG(STAT.st_mode))
		output[L_ROW][1][0] = '-';
	if (S_ISDIR(STAT.st_mode))
		output[L_ROW][1][0] = 'd';
	if (S_ISCHR(STAT.st_mode))
		output[L_ROW][1][0] = 'c';
	if (S_ISBLK(STAT.st_mode))
		output[L_ROW][1][0] = 'b';
	if (S_ISFIFO(STAT.st_mode))
		output[L_ROW][1][0] = 'p';
	if (S_ISSOCK(STAT.st_mode))
		output[L_ROW][1][0] = 's';
	ft_pmode_acc(file, output, c_w);
}

void	ft_add_nlink(t_file *file, char ***output, int c_w[L_WIDTH])
{
	int		nlink_len;
	int		space_count;
	int		space_mode;

	space_count = (ft_strlen(output[L_ROW][1]) > 10) ? 1 : 2;
	space_mode = (ft_strlen(output[L_ROW][1]) > 10) ? 0 : 1;
	output[L_ROW][2] = ft_itoa((int)(STAT.st_nlink));
	nlink_len = ft_strlen(output[L_ROW][2]);
	if (c_w[2] <= (nlink_len + space_mode))
		c_w[2] = nlink_len + space_count;
}

void	ft_add_uname(t_file *file, char ***output, int c_w[L_WIDTH])
{
	int				uname_len;
	struct passwd	*new;

	new = getpwuid(STAT.st_uid);
	if (!new)
		output[L_ROW][3] = ft_itoa((int)STAT.st_uid);
	else
		output[L_ROW][3] = ft_strdup(new->pw_name);
	uname_len = ft_strlen(output[L_ROW][3]);
	if (c_w[3] < uname_len)
		c_w[3] = uname_len + 1;
}
