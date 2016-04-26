/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_verbose.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 04:38:09 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/26 09:22:35 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void			ps_colors(t_psdata *ps)
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

void			ps_stack_print(t_psdata *ps, t_psstack *read)
{
	int			stop;

	if (!read && ft_printf("%s%s%s\n", ps->cblu, "[STACK] empty", ps->cwhi))
		return ;
	stop = read->val;
	read = read->n;
	ft_printf("%s%s ", ps->cblu, "[STACK] ");
	while (read->val != stop)
	{
		ft_printf("%d ", read->val);
		read = read->n;
	}
	ft_printf("%d%s\n", read->val, ps->cwhi);
}

void			ps_verbose2(t_psdata *ps, int msg)
{
	if (!ps->verb)
		return ;
	ps_verbose(ps, msg);
}

void			ps_verbose_color(t_psdata *ps, int msg)
{
	if (!ps->col)
		return ;
	if (msg == 0)
		ft_putstr(ps->cwhi);
	else if (msg >= 1 && msg <= 9)
		ft_putstr(ps->cred);
	else
		ft_putstr(ps->cyel);
}

int				ps_verbose(t_psdata *ps, int msg)
{
	static char		ret[101][512];

	if (!ps->verb)
		return (1);
	if (ret[1][0] == '\0')
		ps_verbose_init(ret);
	ps_verbose_color(ps, msg);
	ft_putstr(ret[msg]);
	ps_verbose_color(ps, 0);
	return (1);
}
