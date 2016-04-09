/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_stack_move.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 13:43:08 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/09 06:07:48 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ps_stack_move_swap(t_psstack **root)
{
	t_psstack	*last;
	t_psstack	*prev;
	int			val;

	if (!(*root) || !((*root)->next))
		return ;
	last = *root;
	while (last->next)
		last = last->next;
	prev = last->prev;
	val = last->val;
	last->val = prev->val;
	prev->val = val;
}

void		ps_stack_move_rotate(t_psstack **root)
{
	t_psstack	*stack;

	if (!(stack = *root) || !((*root)->next))
		return ;
	while (stack->next)
		stack = stack->next;
	ps_stack_changelist(&(*root), 1, &(*root), 0);
}

void		ps_stack_move_revrotate(t_psstack **root)
{
	t_psstack	*stack;

	if (!(stack = *root) || !((*root)->next))
		return ;
	ps_stack_changelist(&(*root), 0, &(*root), 1);
}

void		ps_stack_move_push(t_psstack **src, t_psstack **dst)
{
	t_psstack	*stack;

	if (!(stack = *src))
		return ;
	while (stack->next)
		stack = stack->next;
	ps_stack_changelist(&(*src), 1, &(*dst), 1);
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
