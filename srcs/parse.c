/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:15:13 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/15 22:17:26 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	illegal_option(char c, char *bin_name)
{
	ft_putstr(bin_name);
	ft_putstr(": illegal option -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putstr(USAGE_MESSAGE);
	exit(MAJOR_PROBLEM);
}

static void	set_conflicting_flag(t_flags *f, char c)
{
	if (c == '1')
	{
		f->l = 0;
		f->one = 1;
	}
	else if (c == 'f')
	{
		f->f = 1;
		f->a = 1;
	}
	else if (c == 'l')
	{
		f->one = 0;
		f->l = 1;
	}
}

static void	set_flag(t_flags *f, char c)
{
	if (c == 'A')
		f->a_big = 1;
	else if (c == 'R')
		f->r_big = 1;
	else if (c == 'S')
		f->s_big = 1;
	else if (c == 'a')
		f->a = 1;
	else if (c == 'h')
		f->h = 1;
	else if (c == 'i')
		f->i = 1;
	else if (c == 'r')
		f->r = 1;
	else if (c == 't')
		f->t = 1;
	else
		set_conflicting_flag(f, c);
}

int			parse_args(t_flags *f, int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] != '-' || !argv[i][1])
			break ;
		j = 0;
		while (argv[i][++j])
		{
			if (ft_strfind(ALLOWED_OPTIONS, argv[i][j]) == -1)
				illegal_option(argv[i][j], argv[0]);
			set_flag(f, argv[i][j]);
		}
	}
	if (argc - i > 1)
		f->print_dirs = 1;
	return (i);
}
