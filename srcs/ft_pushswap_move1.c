/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_move1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:13:41 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/18 21:22:13 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void			ps_move1_swap(t_psdata *ps, t_psstack *stack)
{
	int		val;
	int		i;

	val = stack->val;
	i = stack->i;
	stack->val = (stack->prev)->val;
	stack->i = (stack->prev)->i;
	(stack->prev)->val = val;
	(stack->prev)->i = i;
}

void			ps_move1_push(t_psdata *ps, t_psstack **src, t_psstack **dst)
{
	t_psstack			*cut;

	cut = *src;
	((*src)->prev)->next = (*src)->next;
	((*src)->next)->prev = (*src)->prev;
	*src = ((*src)->prev == (*src)) ? NULL : (*src)->prev;
	if (!(*dst))
	{
		*dst = cut;
		(*dst)->next = cut;
		(*dst)->prev = cut;
		return ;
	}
	cut->prev = (*dst);
	cut->next = (*dst)->next;
	((*dst)->next)->prev = cut;
	(*dst)->next = cut;
	(*dst)->prev = ((*dst)->prev == *dst) ? cut : (*dst)->prev;
	*dst = cut;
}

void		ps_move1(t_psdata *ps, enum move move)
{
	if (move == sa || move == ss)
		ps_move1_swap(ps, ps->st1a);
	if (move == sb || move == ss)
		ps_move1_swap(ps, ps->st1b);
	if (move == pa)
		ps_move1_push(ps, &ps->st1b, &ps->st1a);
	if (move == pb)
		ps_move1_push(ps, &ps->st1a, &ps->st1b);
	if (move == ra || move == rr)
		ps->st1a = ps->st1a->prev;
	if (move == rb || move == rr)
		ps->st1b = ps->st1b->prev;
	if (move == rra || move == rrr)
		ps->st1a = ps->st1a->next;
	if (move == rrb || move == rrr)
		ps->st1b = ps->st1b->next;
}
