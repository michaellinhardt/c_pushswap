/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_solver.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 01:18:09 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/21 06:15:35 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int			ps_issolved(t_psdata *ps, t_psstack *x)
{
	t_psstack	*s;

	if (!x)
		return (1);
	s = ps->s;
	while (x->val != s->val)
		x = x->n;
	while (s)
	{
		if (s->val != x->val)
			return (0);
		s = s->n;
		x = x->n;
	}
	return (1);
}

void		ps_solve_add(t_psdata *ps, int val)
{
	t_psstack	*new;
	t_psstack	*last;
	t_psstack	*s;

	if (!(new = (t_psstack *)malloc(sizeof(t_psstack))))
		ps_error(ps, 100);
	ft_bzero(new, sizeof(t_psstack));
	new->val = val;
	if (!(ps->s) && ((ps->s = new) || 1))
		return ;
	if (val > ps->s->val && ((new->n = ps->s) || 1))
	{
		ps->s = new;
		return ;
	}
	s = ps->s;
	while (s->n && s->val > val && (last = s))
		s = s->n;
	if (s->val > val && ((new->n = s->n) || 1))
		s->n = new;
	else
	{
		last->n = new;
		new->n = s;
	}
}

int			ps_solv(t_psdata *ps)
{
	t_psstack	*x;

	if (!(x = ps->st2a))
		return (1);
	while (!x->stop)
	{
		ps_solve_add(ps, x->val);
		x = x->n;
		x->stop = (x->val == ps->st2a->val) ? 1 : 0;
	}
	x->stop = 0;
	return (1);
}
