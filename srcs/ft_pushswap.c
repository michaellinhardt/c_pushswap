/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 04:38:09 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/24 08:44:46 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ps_error(t_psdata *ps, int er)
{
	ps_verbose(ps, er);
	ft_putstr("Error\n");
	ps_stack_free(ps);
	exit(1);
}

void		ps_display(t_psdata *ps)
{
	char	*s;

	if (ps->count < 70)
	{
		if ((ps->nb1 <= ps->nb2 && ps->nb1 <= ps->nb3 && ps->nb1 <= ps->nb4
			&& ps->nb1 <= ps->nb5) && ((ps->i = ps->nb1) || 1))
			s = ps->log1;
		if ((ps->nb2 <= ps->nb1 && ps->nb2 <= ps->nb3 && ps->nb2 <= ps->nb4
			&& ps->nb2 <= ps->nb5) && ((ps->i = ps->nb2) || 1))
			s = ps->log2;
		if ((ps->nb3 <= ps->nb1 && ps->nb3 <= ps->nb2 && ps->nb3 <= ps->nb4
			&& ps->nb3 <= ps->nb5) && ((ps->i = ps->nb3) || 1))
			s = ps->log3;
		if ((ps->nb4 <= ps->nb1 && ps->nb4 <= ps->nb2 && ps->nb4 <= ps->nb3
			&& ps->nb4 <= ps->nb5) && ((ps->i = ps->nb4) || 1))
			s = ps->log4;
		if ((ps->nb5 <= ps->nb1 && ps->nb5 <= ps->nb2 && ps->nb5 <= ps->nb3
			&& ps->nb5 <= ps->nb4) && ((ps->i = ps->nb5) || 1))
			s = ps->log5;
	}
	else if ((ps->i = ps->nb2) || 1)
		s = ps->log2;
	if (s && s++)
		ft_printf("%s\n", s);
}

void		ps_runalgo(t_psdata *ps, int argc, char **argv)
{
	if (ps->verb && ft_printf("%s[PARSE] %d value are stored:%s\n"
		, ps->cyel, ps->count, ps->cwhi))
		ps_stack_print(ps, ps->st2a);
	argc = (ps->verb) ? ft_printf("%s[PARSE] min: %d, max: %d, total: %d%s\n",
		ps->cyel, ps->min, ps->max, ps->count, ps->cwhi) : argc;
	argc = ((ps_verbose(ps, 20)) && (ps_solv(ps)) && (ps_stupid(ps))) ? 1 : 0;
	argc = (ps->verb) ? ft_printf("%s[ALGO] stupid++ finish: %d move(s)%s\n",
		ps->cyel, ps->nb2, ps->cwhi) : argc;
	if (ps->count < 70)
	{
		argc = ((ps_verbose(ps, 21)) && (ps_bubble1(ps))) ? 1 : 0;
		argc = (ps->verb) ? ft_printf("%s[ALGO] bubble1 finish: %d move(s)%s\n",
			ps->cyel, ps->nb3, ps->cwhi) : argc;
		argc = ((ps_verbose(ps, 22)) && (ps_bubble2(ps))) ? 1 : 0;
		argc = (ps->verb) ? ft_printf("%s[ALGO] bubble2 finish: %d move(s)%s\n",
			ps->cyel, ps->nb4, ps->cwhi) : argc;
		argc = ((ps_verbose(ps, 24)) && (ps_bubble3(ps))) ? 1 : 0;
		argc = (ps->verb) ? ft_printf("%s[ALGO] bubble3 finish: %d move(s)%s\n",
			ps->cyel, ps->nb1, ps->cwhi) : argc;
		argc = ((ps_verbose(ps, 23)) && (ps_stupid2(ps))) ? 1 : 0;
		argc = (ps->verb) ? ft_printf("%s[ALGO] stupid finish: %d move(s)%s\n",
			ps->cyel, ps->nb5, ps->cwhi) : argc;
	}
}

int			main(int argc, char **argv)
{
	t_psdata	ps;

	ft_bzero((void **)&ps, sizeof(t_psdata));
	if (argc > 1)
	{
		ps_parse_options(&ps, argv);
		ps_parse_array(&ps, argv);
		ps_parse_double(&ps);
		ps_runalgo(&ps, argc, argv);
	}
	ps_display(&ps);
	if (ps.verb)
		ft_printf(".. in %d move(s)\n", ps.i);
	ps_stack_free(&ps);
	return (0);
}

