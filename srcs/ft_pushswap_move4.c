/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_move4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:13:41 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/25 00:21:55 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void			ps_move4_swap(t_psstack *stack)
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

void			ps_move4_push(t_psstack **src, t_psstack **dst)
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

void		ps_move4_log(t_psdata *ps, enum move move)
{
	char		*tmp;

	tmp = ps->log4;
	if (move == sa)
		ft_printf("%-!%s sa", &ps->log4, tmp);
	if (move == sb)
		ft_printf("%-!%s sb", &ps->log4, tmp);
	if (move == ss)
		ft_printf("%-!%s ss", &ps->log4, tmp);
	if (move == pa)
		ft_printf("%-!%s pa", &ps->log4, tmp);
	if (move == pb)
		ft_printf("%-!%s pb", &ps->log4, tmp);
	if (move == ra)
		ft_printf("%-!%s ra", &ps->log4, tmp);
	if (move == rb)
		ft_printf("%-!%s rb", &ps->log4, tmp);
	if (move == rr)
		ft_printf("%-!%s rr", &ps->log4, tmp);
	if (move == rra)
		ft_printf("%-!%s rra", &ps->log4, tmp);
	if (move == rrb)
		ft_printf("%-!%s rrb", &ps->log4, tmp);
	if (move == rrr)
		ft_printf("%-!%s rrr", &ps->log4, tmp);
}

void		ps_move4_print(t_psdata *ps, enum move move)
{
	if (move == sa)
		ft_printf("[BUBBLE2] move %d: sa\n", ps->nb4);
	if (move == sb)
		ft_printf("[BUBBLE2] move %d: sb\n", ps->nb4);
	if (move == ss)
		ft_printf("[BUBBLE2] move %d: ss\n", ps->nb4);
	if (move == pa)
		ft_printf("[BUBBLE2] move %d: pa\n", ps->nb4);
	if (move == pb)
		ft_printf("[BUBBLE2] move %d: pb\n", ps->nb4);
	if (move == ra)
		ft_printf("[BUBBLE2] move %d: ra\n", ps->nb4);
	if (move == rb)
		ft_printf("[BUBBLE2] move %d: rb\n", ps->nb4);
	if (move == rr)
		ft_printf("[BUBBLE2] move %d: rr\n", ps->nb4);
	if (move == rra)
		ft_printf("[BUBBLE2] move %d: rra\n", ps->nb4);
	if (move == rrb)
		ft_printf("[BUBBLE2] move %d: rrb\n", ps->nb4);
	if (move == rrr)
		ft_printf("[BUBBLE2] move %d: rrr\n", ps->nb4);
	ps_stack_print(ps, ps->st4a);
	ps_stack_print(ps, ps->st4b);
}

int			ps_move4(t_psdata *ps, enum move move)
{
	if (ps->verb)
		ps_move4_print(ps, move);
	if (move == sa || move == ss)
		ps_move4_swap(ps->st4a);
	if (move == sb || move == ss)
		ps_move4_swap(ps->st4b);
	if (move == pa)
		ps_move4_push(&ps->st4b, &ps->st4a);
	if (move == pb)
		ps_move4_push(&ps->st4a, &ps->st4b);
	if (move == ra || move == rr)
		ps->st4a = ps->st4a->p;
	if (move == rb || move == rr)
		ps->st4b = ps->st4b->p;
	if (move == rra || move == rrr)
		ps->st4a = ps->st4a->n;
	if (move == rrb || move == rrr)
		ps->st4b = ps->st4b->n;
	if (!ps->log4 && !(ps->log4 = ft_strnew(0)))
		ps_error(ps, 100);
	ps->nb4++;
	ps_move4_log(ps, move);
	return (1);
}
