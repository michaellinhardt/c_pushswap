/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_stupid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:13:41 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/25 01:56:08 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ps_stupid_solve_add(t_psdata *ps, t_stupid *stu, int val)
{
	t_psstack	*last;
	t_psstack	*new;
	t_psstack	*s;

	if (!(new = (t_psstack *)malloc(sizeof(t_psstack))))
		ps_error(ps, 100);
	ft_bzero(new, sizeof(t_psstack));
	new->val = val;
	if (!(stu->s) && ((stu->s = new) || 1))
		return ;
	if (val < stu->s->val && ((new->n = stu->s) || 1))
	{
		stu->s = new;
		return ;
	}
	s = stu->s;
	while (s->n && s->val < val && (last = s))
		s = s->n;
	if (s->val < val && ((new->n = s->n) || 1))
		s->n = new;
	else
	{
		last->n = new;
		new->n = s;
	}
}

void		ps_stupid_solve(t_psdata *ps, t_stupid *stu)
{
	t_psstack	*x;

	x = ps->st2a;
	while (!x->stop)
	{
		ps_stupid_solve_add(ps, stu, x->val);
		x = x->n;
		x->stop = (x->val == ps->st2a->val) ? 1 : 0;
	}
	x->stop = 0;
}

int			ps_stupid_rotate(t_psdata *ps)
{
	int		ip;
	int		in;
	t_psstack	*x;

	if (!ps->st2a)
		return (1);
	ip = 0;
	in = 0;
	x = ps->st2a;
	while (x->val != ps->min && ++ip)
		x = x->p;
	x = ps->st2a;
	while (x->val != ps->min && ++in)
		x = x->n;
	if (ip <= in)
		while (ip--)
			ps_move2(ps, ra);
	else
		while (in--)
			ps_move2(ps, rra);
	return (1);
}

int			ps_stupid(t_psdata *ps)
{
	t_stupid	stu;
	t_psstack	*destroy;

	if (ps_issolved(ps, ps->st2a) && ps_stupid_rotate(ps))
		return (1);
	ft_bzero(&stu, sizeof(t_stupid));
	ps_stupid_solve(ps, &stu);
	stu.acount = ps->count;
	ps_stupid_pushb(ps, &stu, stu.s, ps->st2a);
	while (ps->st2b)
		ps_move2(ps, pa);
	while (stu.s)
	{
		destroy = stu.s;
		stu.s = stu.s->n;
		ft_memdel((void **)&destroy);
	}
	return (1);
}
