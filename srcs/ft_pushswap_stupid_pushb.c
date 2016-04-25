/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_stupid_pushb.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:13:41 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/25 02:50:52 by mlinhard         ###   ########.fr       */
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
		stu->acount--;
		ps_move2(ps, pb);
		ps_move2(ps, sb);
	}
	else
	{
		stu->i = stu->next;
		while (stu->i--)
			ps_move2(ps, rb);
		stu->acount--;
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
			stu->acount--;
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
		x = ps->st2a;
		while (x->val != s->val && ++stu->ip)
			x = x->p;
		stu->in = (stu->ip) ? stu->acount - stu->ip : 0;
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
