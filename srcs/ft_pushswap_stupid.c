/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_stupid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:13:41 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/26 06:09:17 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ps_stupid_solve_add(t_psdata *ps, t_stupid *stu, int val)
{
	t_psstack	*last;
	t_psstack	*new;
	t_psstack	*s;

	if (!(new = (t_psstack *)malloc(sizeof(t_psstack))))
		ps_error(ps, 100);
	ft_bzero(new, sizeof(t_psstack));
	new->val = val;
	if (!(stu->s) && ((stu->s = new) || 1))
		return ;
	if (val < stu->s->val && ((new->n = stu->s) || 1))
	{
		stu->s = new;
		return ;
	}
	s = stu->s;
	while (s->n && s->val < val && (last = s))
		s = s->n;
	if (s->val < val && ((new->n = s->n) || 1))
		s->n = new;
	else
	{
		last->n = new;
		new->n = s;
	}
}

void		ps_stupid_solve(t_psdata *ps, t_stupid *stu)
{
	t_psstack	*x;

	x = ps->st2a;
	while (!x->stop)
	{
		ps_stupid_solve_add(ps, stu, x->val);
		x = x->n;
		x->stop = (x->val == ps->st2a->val) ? 1 : 0;
	}
	x->stop = 0;
}

int			ps_stupid_rotate(t_psdata *ps)
{
	int		ip;
	int		in;
	t_psstack	*x;

	if (!ps->st2a)
		return (1);
	ip = 0;
	in = 0;
	x = ps->st2a;
	while (x->val != ps->min && ++ip)
		x = x->p;
	x = ps->st2a;
	while (x->val != ps->min && ++in)
		x = x->n;
	if (ip <= in)
		while (ip--)
			ps_move2(ps, ra);
	else
		while (in--)
			ps_move2(ps, rra);
	return (1);
}

void		ps_stupid_pusha_display(t_psdata *ps)
{
	if (!ps->verb)
		return ;
	if (ps->i > 1)
		ft_printf("[STUPID++] moves %d to %d: pa * %d\n", (ps->nb2 - ps->i + 1),
			ps->nb2, ps->i);
	else
		ft_printf("[STUPID++] move %d: pa\n", ps->nb2);
	ps_stack_print(ps, ps->st2a);
	ps_stack_print(ps, ps->st2b);
}

void		ps_stupid_pusha(t_psdata *ps, t_stupid *stu)
{
	char		*tmp;
	char		*str;
	char		*strp;

	tmp = ps->log2;
	ps->i = ps->count - stu->acount;
	if (!(str = ft_strnew((stu->in = ps->i * 3))))
		ps_error(ps, 666);
	strp = str;
	ps->nb2 += ps->i;
	while (stu->in)
	{
		ft_memcpy(strp, " pa", 3);
		strp += 3;
		stu->in -= 3;
	}
	*strp = '\0';
	if (!ps->log2)
		ps->log2 = str;
	else
		ft_printf("%-!%s%s", &ps->log2, tmp, str);
	ps_stupid_pusha_display(ps);
}

int			ps_stupid(t_psdata *ps)
{
	t_stupid	stu;
	t_psstack	*destroy;

	if (ps_issolved(ps, ps->st2a) && ps_stupid_rotate(ps))
		return (1);
	ft_bzero(&stu, sizeof(t_stupid));
	ps_stupid_solve(ps, &stu);
	stu.sfree = stu.s;
	stu.acount = ps->count;
	ps_stupid_pushb(ps, &stu, stu.s, ps->st2a);
	ps_stupid_pusha(ps, &stu);
	while (stu.sfree)
	{
		destroy = stu.sfree;
		stu.sfree = stu.sfree->n;
		ft_memdel((void **)&destroy);
	}
	return (1);
}
