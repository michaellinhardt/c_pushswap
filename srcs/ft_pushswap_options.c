/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_options.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 07:32:57 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/26 09:04:55 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ps_options_help(t_psdata *ps)
{
	int		verb;

	verb = ps->verb;
	ps->verb = 1;
	ps_verbose(ps, 40);
	ps_verbose(ps, 41);
	ps_verbose(ps, 42);
	ps_verbose(ps, 43);
	ps_verbose(ps, 44);
	ps->verb = verb;
}

void		ps_set_options(t_psdata *ps, char c)
{
	if (c == 'v' && (ps->verb = 1))
			ps_verbose(ps, 10);
	else if (c == 'c' && (ps->col = 1))
	{
		ps_colors(ps);
		ps_verbose(ps, 11);
	}
	else if (c == 'h')
		ps->help = 1;
	else
		ps_error(ps, 2);
}

void		ps_options(t_psdata *ps)
{
	if (ps->help)
		ps_options_help(ps);
}
