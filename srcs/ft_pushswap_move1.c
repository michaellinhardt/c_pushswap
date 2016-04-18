/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_move1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:13:41 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/18 21:40:47 by mlinhard         ###   ########.fr       */
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

void		ps_move1_log(t_psdata *ps, enum move move)
{
	char		*tmp;

	tmp = ps->log1;
	if (move == sa)
		ft_printf("%-!%s sa", &ps->log1, tmp);
	if (move == sb)
		ft_printf("%-!%s sb", &ps->log1, tmp);
	if (move == ss)
		ft_printf("%-!%s ss", &ps->log1, tmp);
	if (move == pa)
		ft_printf("%-!%s pa", &ps->log1, tmp);
	if (move == pb)
		ft_printf("%-!%s pb", &ps->log1, tmp);
	if (move == ra)
		ft_printf("%-!%s ra", &ps->log1, tmp);
	if (move == rb)
		ft_printf("%-!%s rb", &ps->log1, tmp);
	if (move == rr)
		ft_printf("%-!%s rr", &ps->log1, tmp);
	if (move == rra)
		ft_printf("%-!%s rra", &ps->log1, tmp);
	if (move == rrb)
		ft_printf("%-!%s rrb", &ps->log1, tmp);
	if (move == rrr)
		ft_printf("%-!%s rrr", &ps->log1, tmp);
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
	if (!ps->log1 && !(ps->log1 = ft_strnew(0)))
		ps_error(ps, 100);
	ps->nb1++;
	ps_move1_log(ps, move);
}
