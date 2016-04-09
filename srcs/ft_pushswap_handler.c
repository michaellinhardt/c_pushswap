/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 06:45:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/09 08:05:41 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ps_stack_add(t_psstack **root, int where, int val)
{
	t_psstack	*new;
	t_psstack	*last;

	if (!(new = (t_psstack *)malloc(sizeof(t_psstack) * 1)))
		ps_error(NULL, 100);
	ft_bzero(new, sizeof(t_psstack));
	new->val = val;
	if (!*root)
		*root = new;
	else if (where == 0)
	{
		last = *root;
		last->prev = new;
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

void		ps_stack_changelist2(t_psstack *move, t_psstack **dst, int dstwhere)
{
	t_psstack	*tmp;

	tmp = *dst;
	if (tmp)
	{
		if (dstwhere)
			while (tmp->next)
				tmp = tmp->next;
		move->prev = (dstwhere) ? tmp : (t_psstack *)NULL;
		move->next = (dstwhere) ? (t_psstack *)NULL : tmp;
		tmp->prev = (dstwhere) ? tmp->prev : move;
		tmp->next = (dstwhere) ? move : tmp->next;
		*dst = (dstwhere) ? *dst : move;
	}
	else
	{
		*dst = move;
		move->next = (t_psstack *)NULL;
		move->prev = (t_psstack *)NULL;
	}
}

void		ps_stack_changelist(t_psstack **src, int srcwhere, t_psstack **dst
						, int dstwhere)
{
	t_psstack	*move;
	t_psstack	*tmp;

	move = *src;
	if (move->next)
	{
		if (srcwhere)
				while (move->next)
					move = move->next;
		tmp = (srcwhere) ? move->prev : move->next;
		tmp->next = (srcwhere) ? (t_psstack *)NULL : tmp->next;
		tmp->prev = (srcwhere) ? tmp->prev : (t_psstack *)NULL;
		*src = (srcwhere) ? *src : tmp;
	}
	else
		*src = (t_psstack *)NULL;
	ps_stack_changelist2(move, &(*dst), dstwhere);
}

void		ps_stack_del(t_psstack **root, int where)
{
	t_psstack	*del;
	t_psstack	*tmp;

	if (!(del = *root))
		return ;
	if (where)
	{
		while (del->next)
			del = del->next;
		if ((tmp = del->prev))
			tmp->next = NULL;
	}
	else
	{
		if ((tmp = del->next))
		{
			tmp->prev = NULL;
			*root = tmp;
		}
	}
	*root = ((!del->prev && where) || (!del->next && !where)) ? NULL : *root;
	ft_memdel((void **)&del);
}
