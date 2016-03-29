/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_stack_handler.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 06:45:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/03/29 11:50:22 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ps_stack_solve_insert(t_psdata *ps, t_psstack *new, t_psstack *next
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

void		ps_stack_solve(t_psdata *ps, t_psstack **root, int id, int val)
{
	t_psstack	*new;
	t_psstack	*next;
	t_psstack	*prev;

	if (!(new = (t_psstack *)malloc(sizeof(t_psstack) * 1)))
		ps_error(ps, 666);
	ft_bzero(new, sizeof(t_psstack));
	new->val = val;
	new->id = id;
	if (!*root)
		*root = new;
	else
	{
		next = *root;
		ps_stack_solve_insert(ps, new, next, prev);
	}
	while (new->prev)
		new = new->prev;
	*root = new;
}

void		ps_stack_add(t_psstack **root, int where, int id, int val)
{
	t_psstack	*new;
	t_psstack	*last;

	if (!(new = (t_psstack *)malloc(sizeof(t_psstack) * 1)))
		ps_error(NULL, 666);
	ft_bzero(new, sizeof(t_psstack));
	new->val = val;
	new->id = id;
	if (!*root)
		*root = new;
	else if (where == 0)
	{
		new->next = *root;
		*root = new;
	}
	else
	{
		last = *root;
		while (last->next)
			last = last->next;
		new->prev = last;
		last->next = new;
	}
}
