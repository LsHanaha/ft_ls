/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_l_params2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:16:27 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 18:39:41 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_print.h"

void	ft_add_group(t_file *file, char ***output, int c_w[L_WIDTH])
{
	int				gname_len;
	struct group	*new;

	new = getgrgid(STAT.st_gid);
	if (!new)
		output[L_ROW][4] = ft_itoa((int)STAT.st_gid);
	else
		output[L_ROW][4] = ft_strdup(new->gr_name);
	gname_len = ft_strlen(output[L_ROW][4]);
	if (c_w[4] < gname_len + 1)
		c_w[4] = gname_len + 2;
}

char	*ft_convert_size(int res, int dec, int i)
{
	int		size;
	char	*value;
	char	*size_str;
	char	mult;

	if (i == 0)
		mult = 'B';
	if (i == 1)
		mult = 'K';
	if (i == 2)
		mult = 'M';
	if (i == 3)
		mult = 'G';
	value = ft_itoa(res);
	size = ft_strlen(value);
	size_str = (char *)ft_strnew(size + 5);
	size_str = ft_memmove(size_str, value, size);
	free(value);
	if (dec != 0 && size < 2)
	{
		size_str[size++] = '.';
		size_str[size++] = dec + '0';
	}
	size_str[size] = mult;
	return (size_str);
}

void	ft_add_size(t_flags *f, t_file *file, char ***output, int c_w[L_WIDTH])
{
	long int		res;
	long int		dec;
	int				i;
	int				size_len;

	i = 0;
	res = 0;
	if (!FLAG_H)
		output[L_ROW][5] = ft_itoa((int)(STAT.st_size));
	else
	{
		while (1)
		{
			dec = res % 1000;
			res = (long int)STAT.st_size;
			if (!(STAT.st_size = STAT.st_size / 1000))
				break ;
			i++;
		}
		dec = (res >= 10) ? 0 : (dec / 100);
		output[L_ROW][5] = ft_convert_size(res, dec, i);
	}
	size_len = ft_strlen(output[L_ROW][5]);
	if (c_w[5] <= size_len)
		c_w[5] = size_len + 2;
}

void	ft_clear_day_month(char *day, char *month)
{
	if (day)
		free(day);
	if (month)
		free(month);
}

void	ft_add_date(t_file *file, char ***output, int c_w[L_WIDTH])
{
	int		date_len;
	char	*month;
	char	*day;
	time_t	seconds;

	seconds = time(NULL);
	output[L_ROW][6] = ft_strdup((ctime(&(STAT.st_mtimespec.tv_sec))));
	month = ft_slice(output[L_ROW][6], 4, 8);
	day = ft_slice(output[L_ROW][6], 8, 11);
	ft_memcpy(output[L_ROW][6], day, 3);
	ft_memcpy(&(output[L_ROW][6])[3], month, 4);
	if (day)
		free(day);
	if ((seconds - ((STAT.st_mtimespec.tv_sec))) < 15778463)
		day = ft_slice(output[L_ROW][6], 11, 16);
	else
		day = ft_slice(output[L_ROW][6], 19, 24);
	ft_memcpy(&(output[L_ROW][6])[7], day, ft_strlen(day) + 1);
	ft_clear_day_month(day, month);
	date_len = ft_strlen(output[L_ROW][6]);
	if (c_w[6] < date_len)
		c_w[6] = date_len + 1;
}
