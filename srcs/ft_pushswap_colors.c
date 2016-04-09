/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_colors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:13:41 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/09 09:06:10 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ps_colors(t_psdata *ps)
{
	if (ps->col == 0)
	{
		ft_bzero(ps->cwhi, 7);
		ft_bzero(ps->cyel, 7);
		ft_bzero(ps->cblu, 7);
		ft_bzero(ps->cred, 7);
	}
	else
	{
		ft_memcpy(ps->cwhi, "\e[39m\0", 6);
		ft_memcpy(ps->cblu, "\e[34m\0", 6);
		ft_memcpy(ps->cyel, "\e[33m\0", 6);
		ft_memcpy(ps->cred, "\e[31m\0", 6);
	}
}
