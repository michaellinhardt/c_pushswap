/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_solve_tools.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:13:41 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/09 04:39:24 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ps_presolve_insert(t_psdata *ps, t_psstack *new, t_psstack *next
									, t_psstack *prev)
{
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
		ps_error(ps, 5);
}

void		ps_presolve_add(t_psdata *ps, t_psstack **root, int val)
{
	t_psstack	*new;
	t_psstack	*prev;

	if (!(new = (t_psstack *)malloc(sizeof(t_psstack) * 1)))
		ps_error(ps, 666);
	ft_bzero(new, sizeof(t_psstack));
	new->val = val;
	if (!*root)
		*root = new;
	else
		ps_presolve_insert(ps, new, *root, prev);
	while (new->prev)
		new = new->prev;
	*root = new;
}
