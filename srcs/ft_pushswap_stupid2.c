/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_stupid2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:13:41 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/24 08:32:43 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ps_stupid2_solve_add(t_psdata *ps, t_stupid2 *stu, int val)
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

void		ps_stupid2_solve(t_psdata *ps, t_stupid2 *stu)
{
	t_psstack	*x;

	x = ps->st5a;
	while (!x->stop)
	{
		ps_stupid2_solve_add(ps, stu, x->val);
		x = x->n;
		x->stop = (x->val == ps->st5a->val) ? 1 : 0;
	}
	x->stop = 0;
}

int			ps_stupid2_rotate(t_psdata *ps)
{
	int		ip;
	int		in;
	t_psstack	*x;

	if (!ps->st5a)
		return (1);
	ip = 0;
	in = 0;
	x = ps->st5a;
	while (x->val != ps->min && ++ip)
		x = x->p;
	x = ps->st5a;
	while (x->val != ps->min && ++in)
		x = x->n;
	if (ip <= in)
		while (ip--)
			ps_move5(ps, ra);
	else
		while (in--)
			ps_move5(ps, rra);
	return (1);
}

void		ps_stupid2_pushb(t_psdata *ps, t_stupid2 *stu, t_psstack *s
						, t_psstack *x)
{
	while (s && s->n)
	{
		stu->ip = 0;
		stu->in = 0;
		x = ps->st5a;
		while (x->val != s->val && ++stu->ip)
			x = x->p;
		x = ps->st5a;
		while (x->val != s->val && ++stu->in)
			x = x->n;
		if (stu->ip <= stu->in)
			while (stu->ip--)
				ps_move5(ps, ra);
		else
			while (stu->in--)
				ps_move5(ps, rra);
		ps_move5(ps, pb);
		s = s->n;
	}
}

int			ps_stupid2(t_psdata *ps)
{
	t_stupid2	stu;
	t_psstack	*destroy;

	if (ps_issolved(ps, ps->st5a) && ps_stupid2_rotate(ps))
		return (1);
	ft_bzero(&stu, sizeof(t_stupid2));
	ps_stupid2_solve(ps, &stu);
	ps_stupid2_pushb(ps, &stu, stu.s, ps->st5a);
	while (ps->st5b)
		ps_move5(ps, pa);
	while (stu.s)
	{
		destroy = stu.s;
		stu.s = stu.s->n;
		ft_memdel((void **)&destroy);
	}
	return (1);
}
