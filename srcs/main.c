/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:15:13 by jrobin-h          #+#    #+#             */
/*   Updated: 2019/09/15 22:12:37 by jrobin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int argc, char **argv)
{
	t_flags	f;
	int		i;
	t_list	*args;
	t_list	*current;

	setlocale(LC_ALL, "");
	errno = 0;
	ft_memset(&f, 0, sizeof(t_flags));
	i = parse_args(&f, argc, argv);
	if (!(args = process_args(&f, argc, argv, i)))
		return (MAJOR_PROBLEM);
	current = send_files_to_output(&f, args);
	while (current)
	{
		ft_ls(&f, ((t_file *)current->content)->name, current->content,
				f.print_dirs ? PDN_YES : PDN_NO);
		if ((current = current->next))
			ft_putchar('\n');
	}
	ft_lstdel(&args, del_lst_file);
	return (errno ? MINOR_PROBLEM : OK);
}
