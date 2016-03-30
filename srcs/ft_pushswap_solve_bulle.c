/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_solve_bulle.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 15:41:15 by mlinhard          #+#    #+#             */
/*   Updated: 2016/03/30 18:54:36 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ps_solve_bulle(t_psdata *ps)
{
	t_psstack	*last;
	t_psstack	*prev;
	int			loop;

	loop = ps->count;
	while (42)
	{
		last = ps->st1->next;
		while (last->next)
			last = last->next;
		prev = last->prev;
		if (last->val > prev->val)
			ps_stack_move(ps, sa);
		ps_stack_move(ps, ra);
		if (--loop < 2)
		{
			loop = ps->count;
			ps_stack_move(ps, ra);
		}
		if (ps_issolved(ps->st1))
			break ;
	}
}
