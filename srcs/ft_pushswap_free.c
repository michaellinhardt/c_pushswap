/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 08:00:15 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/18 01:10:41 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ps_stack_free_one(t_psdata *ps, t_psstack *stack)
{
	int			stop;
	t_psstack	*destroy;

	if (!stack)
		return ;
	stop = stack->val;
	stack = stack->next;
	while (stack->val != stop)
	{
		destroy = stack;
		stack = stack->next;
		ft_memdel((void **)&destroy);
	}
	ft_memdel((void **)&stack);
}

void		ps_stack_free(t_psdata *ps)
{
	ps_stack_free_one(ps, ps->st1a);
	ps_stack_free_one(ps, ps->st1b);
	ps_stack_free_one(ps, ps->st2a);
	ps_stack_free_one(ps, ps->st2b);
}
