/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_stack_move.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 13:43:08 by mlinhard          #+#    #+#             */
/*   Updated: 2016/03/30 14:57:27 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ps_stack_move_swap(t_psstack **root)
{
	t_psstack	*last;
	t_psstack	*prev;
	int			id;
	int			val;

	if (!(*root) || !((*root)->next))
		return ;
	last = *root;
	while (last->next)
		last = last->next;
	prev = last->prev;
	id = last->id;
	val = last->val;
	last->id = prev->id;
	last->val = prev->val;
	prev->id = id;
	prev->val = val;
}

void		ps_stack_move_rotate(t_psstack **root)
{
	t_psstack	*stack;
	int		id;
	int		val;

	if (!(stack = *root) || !((*root)->next))
		return ;
	while (stack->next)
		stack = stack->next;
	id = stack->id;
	val = stack->val;
	ps_stack_del(&(*root), 1);
	ps_stack_add(&(*root), 0, id, val);
}

void		ps_stack_move_revrotate(t_psstack **root)
{
	t_psstack	*stack;
	int		id;
	int		val;

	if (!(stack = *root) || !((*root)->next))
		return ;
	id = stack->id;
	val = stack->val;
	ps_stack_del(&(*root), 0);
	ps_stack_add(&(*root), 1, id, val);
}

void		ps_stack_move_push(t_psstack **src, t_psstack **dst)
{
	t_psstack	*stack;
	int		id;
	int		val;

	if (!(stack = *src))
		return ;
	while (stack->next)
		stack = stack->next;
	id = stack->id;
	val = stack->val;
	ps_stack_del(&(*src), 1);
	ps_stack_add(&(*dst), 1, id, val);
}

void		ps_stack_move(t_psdata *ps, enum move move)
{
	if (move == sa || move == ss)
		ps_stack_move_swap(&ps->st1);
	if (move == sb || move == ss)
		ps_stack_move_swap(&ps->st2);
	if (move == pa)
		ps_stack_move_push(&ps->st2, &ps->st1);
	if (move == pb)
		ps_stack_move_push(&ps->st1, &ps->st2);
	if (move == ra || move == rr)
		ps_stack_move_rotate(&ps->st1);
	if (move == rb || move == rr)
		ps_stack_move_rotate(&ps->st2);
	if (move == rra || move == rrr)
		ps_stack_move_revrotate(&ps->st1);
	if (move == rrb || move == rrr)
		ps_stack_move_revrotate(&ps->st2);
	ps->nbmove++;
}
