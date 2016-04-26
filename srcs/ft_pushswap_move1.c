/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_move1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:13:41 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/26 19:43:19 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void			ps_move1_swap(t_psstack *stack)
{
	int		val;
	int		i;

	val = stack->val;
	i = stack->i;
	stack->val = (stack->p)->val;
	stack->i = (stack->p)->i;
	(stack->p)->val = val;
	(stack->p)->i = i;
}

void			ps_move1_push(t_psstack **src, t_psstack **dst)
{
	t_psstack			*cut;

	cut = *src;
	((*src)->p)->n = (*src)->n;
	((*src)->n)->p = (*src)->p;
	*src = ((*src)->p == (*src)) ? NULL : (*src)->p;
	if (!(*dst))
	{
		*dst = cut;
		(*dst)->n = cut;
		(*dst)->p = cut;
		return ;
	}
	cut->p = (*dst);
	cut->n = (*dst)->n;
	((*dst)->n)->p = cut;
	(*dst)->n = cut;
	(*dst)->p = ((*dst)->p == *dst) ? cut : (*dst)->p;
	*dst = cut;
}

void			ps_move1_log(t_psdata *ps, enum e_move move)
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

void			ps_move1_print(t_psdata *ps, enum e_move move)
{
	if (move == sa)
		ft_printf("[BUBBLE3] move %d: sa\n", (1 + ps->nb1));
	if (move == sb)
		ft_printf("[BUBBLE3] move %d: sb\n", (1 + ps->nb1));
	if (move == ss)
		ft_printf("[BUBBLE3] move %d: ss\n", (1 + ps->nb1));
	if (move == pa)
		ft_printf("[BUBBLE3] move %d: pa\n", (1 + ps->nb1));
	if (move == pb)
		ft_printf("[BUBBLE3] move %d: pb\n", (1 + ps->nb1));
	if (move == ra)
		ft_printf("[BUBBLE3] move %d: ra\n", (1 + ps->nb1));
	if (move == rb)
		ft_printf("[BUBBLE3] move %d: rb\n", (1 + ps->nb1));
	if (move == rr)
		ft_printf("[BUBBLE3] move %d: rr\n", (1 + ps->nb1));
	if (move == rra)
		ft_printf("[BUBBLE3] move %d: rra\n", (1 + ps->nb1));
	if (move == rrb)
		ft_printf("[BUBBLE3] move %d: rrb\n", (1 + ps->nb1));
	if (move == rrr)
		ft_printf("[BUBBLE3] move %d: rrr\n", (1 + ps->nb1));
	ps_stack_print(ps, ps->st1a);
	ps_stack_print(ps, ps->st1b);
}

void			ps_move1(t_psdata *ps, enum e_move move)
{
	if (ps->verb)
		ps_move1_print(ps, move);
	if (move == sa || move == ss)
		ps_move1_swap(ps->st1a);
	if (move == sb || move == ss)
		ps_move1_swap(ps->st1b);
	if (move == pa)
		ps_move1_push(&ps->st1b, &ps->st1a);
	if (move == pb)
		ps_move1_push(&ps->st1a, &ps->st1b);
	if (move == ra || move == rr)
		ps->st1a = ps->st1a->p;
	if (move == rb || move == rr)
		ps->st1b = ps->st1b->p;
	if (move == rra || move == rrr)
		ps->st1a = ps->st1a->n;
	if (move == rrb || move == rrr)
		ps->st1b = ps->st1b->n;
	if (!ps->log1 && !(ps->log1 = ft_strnew(0)))
		ps_error(ps, 100);
	ps->nb1++;
	ps_move1_log(ps, move);
}
