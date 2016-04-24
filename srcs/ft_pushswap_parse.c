/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:13:41 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/24 07:21:53 by mlinhard         ###   ########.fr       */
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
	ps_colors(ps);
	while (argv[1][++i])
	{
		if (argv[1][i] == 'v' && (ps->verb = 1))
			ps_verbose(ps, 10);
		else if (argv[1][i] == 'c' && (ps->col = 1))
		{
			ps_colors(ps);
			ps_verbose(ps, 11);
		}
		else
			ps_error(ps, 2);
	}
	ps->opts = 1;
}

void		ps_parse_add(t_psdata *ps, t_psstack **stack, int val)
{
	t_psstack *new;
	t_psstack *list;

	if (!(new = (t_psstack *)malloc(sizeof(t_psstack))))
		ps_error(ps, 666);
	ft_bzero(new, sizeof(t_psstack));
	new->val = val;
	if (!*stack)
		*stack = new;
	list = ((*stack)->n) ? (*stack)->n : *stack;
	list->p = new;
	new->n = list;
	new->p = *stack;
	(*stack)->n = new;
}

void		ps_parse_double(t_psdata *ps)
{
	t_psstack	*x;
	t_psstack	*y;
	int			loop;

	x = ps->st1a;
	while (!x->stop)
	{
		loop = ps->count;
		y = x->n;
		while (--loop)
		{
			if (y->val == x->val)
				ps_error(ps, 4);
			y = y->n;
		}
		x = x->n;
		x->stop = (x->val == ps->st1a->val) ? 1 : 0;
	}
	x->stop = 0;
}

void		ps_parse_add_all(t_psdata *ps, int val)
{
	ps_parse_add(ps, &ps->st1a, val);
	ps_parse_add(ps, &ps->st2a, val);
	ps_parse_add(ps, &ps->st3a, val);
	ps_parse_add(ps, &ps->st4a, val);
	ps_parse_add(ps, &ps->st5a, val);
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
			ps_error(ps, 3);
		ps->count++;
		ps->min = (ps->count == 1) ? val : ps->min;
		ps->min = (val < ps->min) ? val : ps->min;
		ps->max = (ps->count == 1) ? val : ps->max;
		ps->max = (val > ps->max) ? val : ps->max;
		ps_parse_add_all(ps, val);
	}
}
