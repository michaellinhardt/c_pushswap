/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_move3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:13:41 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/24 07:32:36 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void			ps_move3_swap(t_psdata *ps, t_psstack *stack)
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

void			ps_move3_push(t_psdata *ps, t_psstack **src, t_psstack **dst)
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

void		ps_move3_log(t_psdata *ps, enum move move)
{
	char		*tmp;

	tmp = ps->log3;
	if (move == sa)
		ft_printf("%-!%s sa", &ps->log3, tmp);
	if (move == sb)
		ft_printf("%-!%s sb", &ps->log3, tmp);
	if (move == ss)
		ft_printf("%-!%s ss", &ps->log3, tmp);
	if (move == pa)
		ft_printf("%-!%s pa", &ps->log3, tmp);
	if (move == pb)
		ft_printf("%-!%s pb", &ps->log3, tmp);
	if (move == ra)
		ft_printf("%-!%s ra", &ps->log3, tmp);
	if (move == rb)
		ft_printf("%-!%s rb", &ps->log3, tmp);
	if (move == rr)
		ft_printf("%-!%s rr", &ps->log3, tmp);
	if (move == rra)
		ft_printf("%-!%s rra", &ps->log3, tmp);
	if (move == rrb)
		ft_printf("%-!%s rrb", &ps->log3, tmp);
	if (move == rrr)
		ft_printf("%-!%s rrr", &ps->log3, tmp);
}

void		ps_move3_print(t_psdata *ps, enum move move)
{
	return ;
	if (!ps->verb)
		return ;
	if (move == sa)
		ft_printf("[BUBBLE1] move: sa\n");
	if (move == sb)
		ft_printf("[BUBBLE1] move: sb\n");
	if (move == ss)
		ft_printf("[BUBBLE1] move: ss\n");
	if (move == pa)
		ft_printf("[BUBBLE1] move: pa\n");
	if (move == pb)
		ft_printf("[BUBBLE1] move: pb\n");
	if (move == ra)
		ft_printf("[BUBBLE1] move: ra\n");
	if (move == rb)
		ft_printf("[BUBBLE1] move: rb\n");
	if (move == rr)
		ft_printf("[BUBBLE1] move: rr\n");
	if (move == rra)
		ft_printf("[BUBBLE1] move: rra\n");
	if (move == rrb)
		ft_printf("[BUBBLE1] move: rrb\n");
	if (move == rrr)
		ft_printf("[BUBBLE1] move: rrr\n");
}

void		ps_move3(t_psdata *ps, enum move move)
{
	if (ps->verb)
		ps_move3_print(ps, move);
	if (move == sa || move == ss)
		ps_move3_swap(ps, ps->st3a);
	if (move == sb || move == ss)
		ps_move3_swap(ps, ps->st3b);
	if (move == pa)
		ps_move3_push(ps, &ps->st3b, &ps->st3a);
	if (move == pb)
		ps_move3_push(ps, &ps->st3a, &ps->st3b);
	if (move == ra || move == rr)
		ps->st3a = ps->st3a->p;
	if (move == rb || move == rr)
		ps->st3b = ps->st3b->p;
	if (move == rra || move == rrr)
		ps->st3a = ps->st3a->n;
	if (move == rrb || move == rrr)
		ps->st3b = ps->st3b->n;
	if (!ps->log3 && !(ps->log3 = ft_strnew(0)))
		ps_error(ps, 100);
	ps->nb3++;
	ps_move3_log(ps, move);
}
