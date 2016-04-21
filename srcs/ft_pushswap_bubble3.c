/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_bubble3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:13:41 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/21 06:34:56 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int			ps_bubble3_rotate(t_psdata *ps)
{
	int		ip;
	int		in;
	t_psstack	*x;

	if (!ps->st1a)
		return (1);
	ip = 0;
	in = 0;
	x = ps->st1a;
	while (x->val != ps->min && ++ip)
		x = x->p;
	x = ps->st1a;
	while (x->val != ps->min && ++in)
		x = x->n;
	if (ip <= in)
		while (ip--)
			ps_move1(ps, ra);
	else
		while (in--)
			ps_move1(ps, rra);
	return (1);
}

void		ps_bubble3_run(t_psdata *ps)
{
	t_psstack	*last;
	t_psstack	*prev;
	int			loop;

	loop = ps->count;
	while (42)
	{
		if (ps_issolved(ps, ps->st1a) && ps_bubble3_rotate(ps))
			break ;
		last = ps->st1a;
		prev = last->p;
		if (last->val > prev->val)
			ps_move1(ps, sa);
		if (ps_issolved(ps, ps->st1a) && ps_bubble3_rotate(ps))
			break ;
		ps_move1(ps, ra);
		if (--loop < 2)
		{
			loop = ps->count;
			ps_move1(ps, ra);
		}
	}
}

int			ps_bubble3(t_psdata *ps)
{
	ps_move1(ps, rra);
	ps_move1(ps, rra);
	ps_bubble3_run(ps);
	return (1);
}
