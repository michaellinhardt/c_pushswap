/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_bubble1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:13:41 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/24 23:45:20 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int			ps_bubble1_rotate(t_psdata *ps)
{
	int		ip;
	int		in;
	t_psstack	*x;

	if (!ps->st3a)
		return (1);
	ip = 0;
	in = 0;
	x = ps->st3a;
	while (x->val != ps->min && ++ip)
		x = x->p;
	x = ps->st3a;
	while (x->val != ps->min && ++in)
		x = x->n;
	if (ip <= in)
		while (ip--)
			ps_move3(ps, ra);
	else
		while (in--)
			ps_move3(ps, rra);
	return (1);
}

int			ps_bubble1_break(t_psdata *ps)
{
	if (ps->nb3 > ps->nb2)
	{
		ps->nb3 = INT_MAX;
		ps_verbose(ps, 34);
		return (1);
	}
	return (0);
}

void		ps_bubble1_run(t_psdata *ps)
{
	t_psstack	*last;
	t_psstack	*prev;
	int			loop;

	loop = ps->count;
	while (42)
	{
		if ((ps_issolved(ps, ps->st3a) && ps_bubble1_rotate(ps))
			|| ps_bubble1_break(ps))
			break ;
		last = ps->st3a;
		prev = last->p;
		if (last->val > prev->val)
			ps_move3(ps, sa);
		if (ps_issolved(ps, ps->st3a) && ps_bubble1_rotate(ps))
			break ;
		ps_move3(ps, ra);
		if (--loop < 2)
		{
			loop = ps->count;
			ps_move3(ps, ra);
		}
	}
}

int			ps_bubble1(t_psdata *ps)
{
	ps_bubble1_run(ps);
	return (1);
}
