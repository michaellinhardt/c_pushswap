/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 04:38:09 by mlinhard          #+#    #+#             */
/*   Updated: 2016/03/29 14:17:37 by mlinhard         ###   ########.fr       */
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

argv = ft_strsplit("a.out -vc 1 2 3 4 5 6", ' '); argc = 2;

	ft_bzero((void **)&ps, sizeof(t_psdata));
	if (argc == 1)
		ps_error(&ps, 1);
	ps_parse_options(&ps, argv);
	ps_parse_array(&ps, argv);

	ps_stack_print_full(ps.st1);
	ps_stack_move(&ps, ss);
	ps_stack_print_full(ps.st1);

	// ps_stack_del(&ps.st1, 0);
	// ps_stack_add(&ps.st1, 1, 6, 6);
	// ps_stack_del(&ps.st1, 0);
	// ps_stack_add(&ps.st1, 1, 5, 5);
	// ps_stack_del(&ps.st1, 0);
	// ps_stack_add(&ps.st1, 1, 4, 4);
	// ps_stack_del(&ps.st1, 1);
	// ps_stack_add(&ps.st1, 0, 4, 4);
	// ps_stack_print_full(ps.st1);

ps_test_free(argv);

	ps_stack_free(&ps);
	return (0);
}

