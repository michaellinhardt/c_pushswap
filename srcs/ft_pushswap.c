/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 04:38:09 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/21 06:22:31 by mlinhard         ###   ########.fr       */
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

void		ps_display(t_psdata *ps)
{
	int		winner;
	int		len;
	char	*s;

	winner = (ps->nb2 <= ps->nb3) ? 2 : 3;
	if (winner == 2)
		winner = (ps->nb2 <= ps->nb4) ? 2 : 4;
	else
		winner = (ps->nb3 <= ps->nb4) ? 3 : 4;
	if (winner == 2)
		s = ps->log2;
	if (winner == 3)
		s = ps->log3;
	if (winner == 4)
		s = ps->log4;
	if (!s)
		ft_printf("\n");
	else if (s && s++)
	ft_printf("%s\n", s);
}

int			main(int argc, char **argv)
{
	t_psdata	ps;

argv = ft_strsplit("a.out -v 1 2 10 3 8 0", ' '); argc = 2;

	ft_bzero((void **)&ps, sizeof(t_psdata));
	if (argc == 1)
		ps_error(&ps, 1);
	ps_parse_options(&ps, argv);
	ps_parse_array(&ps, argv);
	if (ps.verb && ft_printf("%s[PARSE] %d value are stored:%s\n"
		, ps.cyel, ps.count, ps.cwhi))
		ps_stack_print(&ps, ps.st2a);
	argc = (ps.verb) ? ft_printf("%s[PARSE] min: %d, max: %d, total: %d%s\n",
		ps.cyel,ps.min, ps.max, ps.count, ps.cwhi) : argc;
	argc = ((ps_verbose(&ps, 5)) && (ps_solv(&ps)) && (ps_stupid(&ps))) ? 1 : 0;
	argc = (ps.verb) ? ft_printf("%s[ALGO] stupid finish in %d move(s)%s\n",
		ps.cyel, ps.nb2, ps.cwhi) : argc;
	argc = ((ps_verbose(&ps, 21)) && (ps_bubble1(&ps))) ? 1 : 0;
	argc = (ps.verb) ? ft_printf("%s[ALGO] bubble1 finish in %d move(s)%s\n",
		ps.cyel, ps.nb3, ps.cwhi) : argc;
	argc = ((ps_verbose(&ps, 22)) && (ps_bubble2(&ps))) ? 1 : 0;
	argc = (ps.verb) ? ft_printf("%s[ALGO] bubble2 finish in %d move(s)%s\n",
		ps.cyel, ps.nb4, ps.cwhi) : argc;
	ps_display(&ps);

ps_test_free(argv);

	ps_stack_free(&ps);
	return (0);
}

