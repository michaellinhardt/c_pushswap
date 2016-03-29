/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_stack_print.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 06:45:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/03/29 09:45:25 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ps_stack_print_full(t_psstack *root)
{
	t_psstack *stack;

	stack = root;
	if (stack)
	{
		printf("****************\n");
		printf("%-6s |  %-6s\n", "ID", "VAL");
		while (stack)
		{
			printf("%-6d |  %-6d\n", stack->id, stack->val);
			stack = stack->next;
		}
		printf("****************\n");
	}
}
