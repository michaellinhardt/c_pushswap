/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_presolve.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:13:41 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/16 04:22:14 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ps_presolve_insert(t_psdata *ps, t_psstack *new, t_psstack *prev)
{
	t_psstack	*next;

	next = ps->st3;
	while (next->next && next->val > new->val)
		next = next->next;
	if (next->val > new->val)
	{
		next->next = new;
		new->prev = next;
	}
	else
	{
		if ((prev = next->prev))
			prev->next = new;
		new->prev = prev;
		new->next = next;
		next->prev = new;
	}
	if (new->val == next->val)
		ps_error(ps, 4);
}

int			ps_presolve_rotate(t_psdata *ps)
{
	t_psstack *list;
	t_psstack *solved;

	list = ps->st1;
	solved = ps->st3;
	ps->i = 1;
	while (list->val != solved->val && ps->i++)
		list = list->next;
	if (ps->i == 1)
		return (1);
	else
	{
		if ((ps->i - 1) <= (ps->count - ps->i))
			while (ps->i != 1 && ps->i--)
				ps_stack_move(ps, rra);
		else
			while (ps->i != (ps->count + 1) && ps->i++)
				ps_stack_move(ps, ra);
	}
	return (1);
}

int			ps_presolve(t_psdata *ps)
{
	ps_presolve_eval(ps);
	if (!ps->err)
		return (ps_presolve_rotate(ps));
	return (0);
}

void		ps_presolve_add(t_psdata *ps, int val)
{
	t_psstack	*new;
	t_psstack	*prev;

	if (!(new = (t_psstack *)malloc(sizeof(t_psstack) * 1)))
		ps_error(ps, 100);
	ft_bzero(new, sizeof(t_psstack));
	new->val = val;
	if (!ps->st3)
		ps->st3 = new;
	else
		ps_presolve_insert(ps, new, prev);
	while (new->prev)
		new = new->prev;
	ps->st3 = new;
}
