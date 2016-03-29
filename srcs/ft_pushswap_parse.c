/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:13:41 by mlinhard          #+#    #+#             */
/*   Updated: 2016/03/29 06:30:03 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int			ps_parse_options(t_psdata *ps, char **argv)
{
	int		i;

	if (!(i = 0) && argv[1][0] != '-')
		return (0);
	if (!argv[1][1])
		return (1);
	if (argv[1][1] && argv[1][1] >= '0' && argv[1][1] <= '9')
		return (0);
	while (argv[1][++i])
	{
		if (argv[1][i] == 'v')
			ps->verb = 1;
		else if (argv[1][i] == 'c')
			ps->col = 1;
		else
			return (1);
	}
	ps->opts = 1;
	return (0);
}

int			ps_parse_array(t_psdata *ps, char **argv)
{
	int		i;
	int		j;

	i = ps->opts;
	while (argv[++i] && (j = -1))
	{
		if (argv[i][++j] != '-' && !ft_isdigit(argv[i][j]))
			return (1);
		while (argv[i][++j])
			if (!ft_isdigit(argv[i][j]))
				return (1);
	}
	return (0);
}
