/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_verbose.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 04:38:09 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/09 07:34:42 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ps_verbose_init(t_psdata *ps, char ret[667][1024])
{
	ft_memcpy(ret[1], "[ERROR] too few argument(s)\n", 28);
	ft_memcpy(ret[2], "[ERROR] bad option found, use -h for help\n", 42);
	ft_memcpy(ret[3], "[ERROR] only int are allowed\n", 29);
	ft_memcpy(ret[4], "[ERROR] duplicated value\n", 25);

	ft_memcpy(ret[10], "[PARSE] verbose activated\n", 31);
	ft_memcpy(ret[11], "[PARSE] color activated\n", 31);

	ft_memcpy(ret[666], "[ERROR] cant malloc\n", 20);
}

void	ps_verbose2(t_psdata *ps, int msg)
{
	if (!(ps->verb))
		return ;
	ps_verbose(ps, msg);
}

int		ps_verbose(t_psdata *ps, int msg)
{
	static char		ret[667][1024] = {0};

	if (!(ps->verb))
		return (1);
	if (ret[1][0] == '\0')
		ps_verbose_init(ps, ret);
	ft_putstr(ret[msg]);
	return (1);
}
