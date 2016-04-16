/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_verbose.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 04:38:09 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/11 15:21:42 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ps_verbose_init(t_psdata *ps, char ret[101][512])
{
	ft_memcpy(ret[1], "[ERROR] too few argument(s)\n", 28);
	ft_memcpy(ret[2], "[ERROR] bad option found, use -h for help\n", 42);
	ft_memcpy(ret[3], "[ERROR] only int are allowed\n", 29);
	ft_memcpy(ret[4], "[ERROR] duplicated value\n", 25);

	ft_memcpy(ret[10], "[PARSE] verbose activated\n", 31);
	ft_memcpy(ret[11], "[PARSE] color activated\n", 31);

	ft_memcpy(ret[20], "[ALGO] expected solution:\n", 26);

	ft_memcpy(ret[100], "[ERROR] cant malloc\n", 20);
}

void	ps_verbose2(t_psdata *ps, int msg)
{
	if (!ps->verb)
		return ;
	ps_verbose(ps, msg);
}

void	ps_verbose_color(t_psdata *ps, int msg)
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

int		ps_verbose(t_psdata *ps, int msg)
{
	static char		ret[101][512] = {0};

	if (!ps->verb)
		return (1);
	if (ret[1][0] == '\0')
		ps_verbose_init(ps, ret);
	ps_verbose_color(ps, msg);
	ft_putstr(ret[msg]);
	ps_verbose_color(ps, 0);
	return (1);
}
