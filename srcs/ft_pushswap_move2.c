/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_move2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:13:41 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/20 22:34:50 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void			ps_move2_swap(t_psdata *ps, t_psstack *stack)
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

void			ps_move2_push(t_psdata *ps, t_psstack **src, t_psstack **dst)
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

void		ps_move2_log(t_psdata *ps, enum move move)
{
	char		*tmp;

	tmp = ps->log2;
	if (move == sa)
		ft_printf("%-!%s sa", &ps->log2, tmp);
	if (move == sb)
		ft_printf("%-!%s sb", &ps->log2, tmp);
	if (move == ss)
		ft_printf("%-!%s ss", &ps->log2, tmp);
	if (move == pa)
		ft_printf("%-!%s pa", &ps->log2, tmp);
	if (move == pb)
		ft_printf("%-!%s pb", &ps->log2, tmp);
	if (move == ra)
		ft_printf("%-!%s ra", &ps->log2, tmp);
	if (move == rb)
		ft_printf("%-!%s rb", &ps->log2, tmp);
	if (move == rr)
		ft_printf("%-!%s rr", &ps->log2, tmp);
	if (move == rra)
		ft_printf("%-!%s rra", &ps->log2, tmp);
	if (move == rrb)
		ft_printf("%-!%s rrb", &ps->log2, tmp);
	if (move == rrr)
		ft_printf("%-!%s rrr", &ps->log2, tmp);
}

void		ps_move2(t_psdata *ps, enum move move)
{
	if (move == sa || move == ss)
		ps_move2_swap(ps, ps->st2a);
	if (move == sb || move == ss)
		ps_move2_swap(ps, ps->st2b);
	if (move == pa)
		ps_move2_push(ps, &ps->st2b, &ps->st2a);
	if (move == pb)
		ps_move2_push(ps, &ps->st2a, &ps->st2b);
	if (move == ra || move == rr)
		ps->st2a = ps->st2a->p;
	if (move == rb || move == rr)
		ps->st2b = ps->st2b->p;
	if (move == rra || move == rrr)
		ps->st2a = ps->st2a->n;
	if (move == rrb || move == rrr)
		ps->st2b = ps->st2b->n;
	if (!ps->log2 && !(ps->log2 = ft_strnew(0)))
		ps_error(ps, 100);
	ps->nb2++;
	ps_move2_log(ps, move);
}
