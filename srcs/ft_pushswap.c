/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 04:38:09 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/18 21:22:16 by mlinhard         ###   ########.fr       */
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

argv = ft_strsplit("a.out -v 2 1 3 6 5 8", ' '); argc = 2;

	ft_bzero((void **)&ps, sizeof(t_psdata));
	if (argc == 1)
		ps_error(&ps, 1);
	ps_parse_options(&ps, argv);
	ps_parse_array(&ps, argv);
	if (ps.verb && ft_printf("%s[PARSE] %s%d%s value are stored:%s\n"
		, ps.cyel, ps.cred, ps.count, ps.cyel, ps.cwhi))
		ps_stack_print(&ps, ps.st1a);

	ft_printf("\n\n");
	ps_move1(&ps, sa); ps_stack_print(&ps, ps.st1a); ps_stack_print(&ps, ps.st1b);
	ps_move1(&ps, pb); ps_stack_print(&ps, ps.st1a); ps_stack_print(&ps, ps.st1b);
	ps_move1(&ps, pb); ps_stack_print(&ps, ps.st1a); ps_stack_print(&ps, ps.st1b);
	ps_move1(&ps, pb); ps_stack_print(&ps, ps.st1a); ps_stack_print(&ps, ps.st1b);
	ps_move1(&ps, sa); ps_stack_print(&ps, ps.st1a); ps_stack_print(&ps, ps.st1b);
	ps_move1(&ps, pa); ps_stack_print(&ps, ps.st1a); ps_stack_print(&ps, ps.st1b);
	ps_move1(&ps, pa); ps_stack_print(&ps, ps.st1a); ps_stack_print(&ps, ps.st1b);
	ps_move1(&ps, pa); ps_stack_print(&ps, ps.st1a); ps_stack_print(&ps, ps.st1b);

ps_test_free(argv);

	ps_stack_free(&ps);
	return (0);
}

