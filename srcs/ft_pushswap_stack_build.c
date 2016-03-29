/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_stack_build.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 06:45:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/03/29 08:05:52 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ps_stack_add(t_psdata *ps, int val)
{
	t_psstack	*st1;

	if (!(st1 = (t_psstack *)malloc(sizeof(t_psstack) * 1)))
		ps_error(ps, 666);
	st1->prev = NULL;
	st1->next = (ps->st1) ? ps->st1 : NULL;
	st1->id = ps->count;
	st1->val = val;
	ps->st1 = st1;
}
