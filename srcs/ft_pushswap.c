/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 04:38:09 by mlinhard          #+#    #+#             */
/*   Updated: 2016/03/30 18:55:31 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
	if (er == 1)
		ft_putstr("Error: too few argument(s).\n");
	if (er == 2)
		ft_putstr("Error: bad option(s).\n");
	if (er == 3)
		ft_putstr("Error: bad argument(s).\n");
	if (er == 4)
		ft_putstr("Error: only int are allowed.\n");
	if (er == 5)
		ft_putstr("Error: duplicated value.\n");
	if (er == 666)
		ft_putstr("Error: cant malloc.\n");
	ps_stack_free(ps);
	exit(1);
}

int			main(int argc, char **argv)
{
	t_psdata	ps;

argv = ft_strsplit("a.out 4 5 6 1 7 3 8 0 98 7685 5528 296 28 262 38 6282 826 863 793 9 6168 376 -3", ' '); argc = 2;

	ft_bzero((void **)&ps, sizeof(t_psdata));
	if (argc == 1)
		ps_error(&ps, 1);
	ps_parse_options(&ps, argv);
	ps_parse_array(&ps, argv);


	printf("Input value:\n");
	ps_stack_print_full(ps.st1);

	if (!ps_issolved(ps.st1))
		ps_solve_stupid(&ps);

	printf("nbmove: %d\n", ps.nbmove);
	printf("Pile A:\n");
	ps_stack_print_full(ps.st1);
	printf("Pile B:\n");
	ps_stack_print_full(ps.st2);
	printf("Solution:\n");
	ps_stack_print_full(ps.st3);


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

