/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_stack_free.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 08:00:15 by mlinhard          #+#    #+#             */
/*   Updated: 2016/03/29 11:52:59 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ps_stack_free(t_psdata *ps)
{
	t_psstack	*next;
	t_psstack	*del;

	next = ps->st1;
	while (next)
	{
		del = next;
		next = next->next;
		ft_memdel((void **)&del);
	}
	next = ps->st2;
	while (next)
	{
		del = next;
		next = next->next;
		ft_memdel((void **)&del);
	}
	next = ps->st3;
	while (next)
	{
		del = next;
		next = next->next;
		ft_memdel((void **)&del);
	}
}
