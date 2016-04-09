/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:13:41 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/09 04:32:18 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ps_parse_options(t_psdata *ps, char **argv)
{
	int			i;

	if (!(i = 0) && argv[1][0] != '-')
		return ;
	if (!argv[1][1])
		ps_error(ps, 2);
	if (argv[1][1] && argv[1][1] >= '0' && argv[1][1] <= '9')
		return ;
	while (argv[1][++i])
	{
		if (argv[1][i] == 'v')
			ps->verb = 1;
		else if (argv[1][i] == 'c')
			ps->col = 1;
		else
			ps_error(ps, 2);
	}
	ps->opts = 1;
}

void		ps_parse_array(t_psdata *ps, char **argv)
{
	int			i;
	int			j;
	intmax_t	val;

	i = ps->opts;
	while (argv[++i] && (j = -1))
	{
		if (argv[i][++j] != '-' && !ft_isdigit(argv[i][j]))
			ps_error(ps, 3);
		while (argv[i][++j])
			if (!ft_isdigit(argv[i][j]))
				ps_error(ps, 3);
		val = ft_atoimax(argv[i]);
		if (val > INT_MAX || val < INT_MIN)
			ps_error(ps, 4);
		ps->count++;
		ps_stack_add(&ps->st1, 0, val);
	}
}
