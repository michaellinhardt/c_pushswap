/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_presolve.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:13:41 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/09 07:37:14 by mlinhard         ###   ########.fr       */
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

void		ps_presolve_add(t_psdata *ps, int val)
{
	t_psstack	*new;
	t_psstack	*prev;

	if (!(new = (t_psstack *)malloc(sizeof(t_psstack) * 1)))
		ps_error(ps, 666);
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
