/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_presolve.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:13:41 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/09 10:57:24 by mlinhard         ###   ########.fr       */
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

int			ps_presolve_start(t_psdata *ps, t_psstack *item, int count)
{
	t_psstack *solved;

	solved = ps->st3;
	ps->i = 9;
	while (item->val != solved->val)
	{
		ft_printf("%d (%d) is false\n", item->val, ps->i);
		if (ps->i == count)
		{
			while (ps->i > 1)
			{
				if (!item->prev)
					while (item->next)
						item = item->next;
				else
					item = item->prev;
				ps->i--;
			}
			ft_printf("%d (%d) move back\n", item->val, ps->i);
		}
		else
		{
			if (!item->next)
				while (item->prev)
					item = item->prev;
			else
				item = item->next;
			ps->i++;
			ft_printf("%d (%d) move next\n", item->val, ps->i);
		}
	}
	ft_printf("%d (%d) is true\n", item->val, ps->i);
	return (1);
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
