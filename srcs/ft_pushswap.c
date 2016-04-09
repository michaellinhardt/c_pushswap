/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 04:38:09 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/09 09:18:52 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ps_test_free(char **argv)
{
	int i = -1;
	while (argv[++i])
		ft_strdel(&argv[i]);
	ft_memdel((void **)&argv);
}

void		ps_error(t_psdata *ps, int er)
{
	ps_verbose(ps, er);
	ft_putstr("Error\n");
	ps_stack_free(ps);
	exit(1);
}

int			main(int argc, char **argv)
{
	t_psdata	ps;

argv = ft_strsplit("a.out -vc 3 2 1 8 -3 12 0", ' '); argc = 2;

	ft_bzero((void **)&ps, sizeof(t_psdata));
	if (argc == 1)
		ps_error(&ps, 1);
	ps_parse_options(&ps, argv);
	ps_parse_array(&ps, argv);


	ft_printf("Input value (%d item):\n", ps.count);
	ps_stack_print_full(ps.st1);
	ft_printf("Solution:\n");
	ps_stack_print_full(ps.st3);

	// ps_issolved(&ps);

	// ps_stack_move(&ps, sa);
	// ps_stack_move(&ps, pb);
	// ps_stack_move(&ps, pb);
	// ps_stack_move(&ps, pb);
	// ps_stack_move(&ps, rr);
	// ps_stack_move(&ps, rrr);
	// ps_stack_move(&ps, sa);
	// ps_stack_move(&ps, pa);
	// ps_stack_move(&ps, pa);
	// ps_stack_move(&ps, pa);
	// ps_stack_print_full(ps.st1);
	// ps_stack_print_full(ps.st2);
ps_test_free(argv);

	ps_stack_free(&ps);
	return (0);
}

