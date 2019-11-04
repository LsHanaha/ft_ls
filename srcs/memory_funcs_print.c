/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_funcs_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:41:51 by lshanaha          #+#    #+#             */
/*   Updated: 2019/09/18 21:35:06 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_print.h"

char	***ft_create_output_string(int term_data[3])
{
	char			***output_string;
	int				i;
	int				j;

	i = 0;
	j = 0;
	output_string = (char ***)ft_strnew(HEIGHT * sizeof(char **));
	while (j < HEIGHT)
	{
		output_string[j] = (char **)ft_strnew(sizeof(char *) * WIDTH);
		while (i < WIDTH)
		{
			output_string[j][i] = (char *)ft_strnew(LENGTH);
			i++;
		}
		i = 0;
		j++;
	}
	return (output_string);
}

void	ft_clean_output_string(char ***output_string, int term_data[3])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < HEIGHT)
	{
		while (i < WIDTH)
		{
			free(output_string[j][i]);
			i++;
		}
		i = 0;
		j++;
	}
	j = 0;
	while (j < HEIGHT)
	{
		free(output_string[j]);
		j++;
	}
	free(output_string);
}

char	***ft_create_l_output(int str_count)
{
	char	***output_string;
	int		row;

	output_string = (char ***)malloc(str_count * sizeof(char **));
	row = 0;
	while (row < str_count)
	{
		output_string[row] = (char **)malloc((L_WIDTH - 4) * sizeof(char *));
		row++;
	}
	return (output_string);
}

void	ft_clean_l_output(char ***output_string, int str_count)
{
	int		row;
	int		column;

	row = 0;
	column = 0;
	while (row < str_count)
	{
		while (column < L_WIDTH - 4)
		{
			free(output_string[row][column]);
			column++;
		}
		free(output_string[row]);
		column = 0;
		row++;
	}
	free(output_string);
}
