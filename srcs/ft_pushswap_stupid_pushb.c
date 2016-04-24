/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_stupid_pushb.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:13:41 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/24 08:02:51 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ps_stupid_pushb_eval3(t_psdata *ps, t_psstack **s, t_stupid *stu)
{
	stu->i = stu->next;
	while (stu->i--)
		*s = (*s)->n;
	if (stu->next == 1)
	{
		ps_move2(ps, pb);
		ps_move2(ps, sb);
	}
	else
	{
		stu->i = stu->next;
		while (stu->i--)
			ps_move2(ps, rb);
		ps_move2(ps, pb);
		while (stu->next--)
			ps_move2(ps, rrb);
	}
	stu->next = 0;
	stu->b++;
}

void		ps_stupid_pushb_eval2(t_psdata *ps, t_psstack **s, t_stupid *stu
								, int mode)
{
	t_psstack *n;

	n = *s;
	stu->i = stu->next + 1;
	while (n && stu->i--)
		n = n->n;
	if (mode != 3)
	{
		if (n && n->n && stu->b && n->val == ps->st2a->val)
		{
			stu->next++;
			ps_move2(ps, pb);
			if (mode == 2)
				stu->in++;
		}
		else if (mode == 1)
			ps_move2(ps, ra);
		else if (mode == 2)
			ps_move2(ps, rra);
	}
	else
		ps_stupid_pushb_eval3(ps, s, stu);
}

void		ps_stupid_pushb(t_psdata *ps, t_stupid *stu, t_psstack *s
						, t_psstack *x)
{
	while (s && s->n)
	{
		stu->ip = 0;
		stu->in = 0;
		x = ps->st2a;
		while (x->val != s->val && ++stu->ip)
			x = x->p;
		x = ps->st2a;
		while (x->val != s->val && ++stu->in)
			x = x->n;
		if (stu->ip <= stu->in)
			while (stu->ip--)
				ps_stupid_pushb_eval2(ps, &s, stu, 1);
		else
			while (stu->in--)
				ps_stupid_pushb_eval2(ps, &s, stu, 2);
		ps_stupid_pushb_eval2(ps, &s, stu, 3);
		s = s->n;
	}
}
