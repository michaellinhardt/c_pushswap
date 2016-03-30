/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:13:41 by mlinhard          #+#    #+#             */
/*   Updated: 2016/03/30 13:03:34 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ps_solve_positions(t_psstack *list)
{
	int		pos;

	pos = 0;
	while (list && (list->pos = ++pos))
		list = list->next;
}

int			ps_issolved(t_psstack *stack)
{
	int		val;

	if (!stack || !stack->next)
		return (1);
	val = stack->val;
	stack = stack->next;
	while (stack)
	{
		if (val < stack->val)
			return (0);
		val = stack->val;
		stack = stack->next;
	}
	return (1);
}
