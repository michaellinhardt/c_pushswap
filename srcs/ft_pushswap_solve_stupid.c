/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_solve_stupid.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 12:39:18 by mlinhard          #+#    #+#             */
/*   Updated: 2016/03/30 15:13:07 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ps_solve_stupid_movetob(t_psdata *ps)
{
	t_psstack	*solved;
	t_psstack	*stack;
	int			count;


	count = ps->count;
	solved = ps->st3;
	while (solved->next)
		solved = solved->next;
	while (solved)
	{
		stack = ps->st1;
		while (stack->val != solved->val)
			stack = stack->next;
		ps->i = count - stack->pos;
		while (ps->i--)
			ps_stack_move(ps, ra);
		ps_stack_move(ps, pb);
		ps_solve_positions(ps->st1);
		solved = solved->prev;
		count--;
	}
	count = ps->count;
	while (count--)
		ps_stack_move(ps, pa);
}

void		ps_solve_stupid(t_psdata *ps)
{
	ps_solve_stupid_movetob(ps);
}
