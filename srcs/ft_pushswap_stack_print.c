/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_stack_print.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 06:45:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/05 02:30:28 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ps_stack_print_full(t_psstack *root)
{
	t_psstack *stack;

	stack = root;
	if (stack)
	{
		printf("********\n");
		printf("%-6s\n", "VAL");
		while (stack)
		{
			printf("%-6d\n", stack->val);
			stack = stack->next;
		}
		printf("********\n");
	}
}
