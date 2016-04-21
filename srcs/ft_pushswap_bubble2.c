/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_bubble2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:13:41 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/21 04:46:17 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int			ps_bubble2_rotate(t_psdata *ps)
{
	int		ip;
	int		in;
	t_psstack	*x;

	if (!ps->st4a)
		return (1);
	ip = 0;
	in = 0;
	x = ps->st4a;
	while (x->val != ps->min && ++ip)
		x = x->p;
	x = ps->st4a;
	while (x->val != ps->min && ++in)
		x = x->n;
	if (ip <= in)
		while (ip--)
			ps_move4(ps, ra);
	else
		while (in--)
			ps_move4(ps, rra);
	return (1);
}

void		ps_bubble2_run(t_psdata *ps)
{
	t_psstack	*last;
	t_psstack	*prev;
	int			loop;

	loop = ps->count;
	while (42)
	{
		if (ps_issolved(ps, ps->st4a) && ps_bubble2_rotate(ps))
			break ;
		last = ps->st4a;
		prev = last->p;
		if (last->val > prev->val)
			ps_move4(ps, sa);
		if (ps_issolved(ps, ps->st4a) && ps_bubble2_rotate(ps))
			break ;
		ps_move4(ps, rra);
		if (--loop < 2)
		{
			loop = ps->count;
			ps_move4(ps, rra);
		}
	}
}

int			ps_bubble2(t_psdata *ps)
{
	ps_bubble2_run(ps);
	return (1);
}
