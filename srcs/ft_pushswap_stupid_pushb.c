/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_stupid_pushb.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:13:41 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/26 05:50:47 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ps_stupid_pushb_rotate_display(t_psdata *ps, t_stupid *stu
									,enum move move)
{
	if (!ps->verb)
		return ;
	if (stu->i > 1)
		ft_printf("[STUPID++] moves %d to %d: %s * %d\n",
			(ps->nb2 - stu->i + 1), ps->nb2, ((move == ra) ? "ra" : "rra"),
				stu->i);
	else
		ft_printf("[STUPID++] move %d: %s\n", ps->nb2,
			((move == ra) ? "ra" : "rra"));
	ps_stack_print(ps, ps->st2a);
	ps_stack_print(ps, ps->st2b);
}

void		ps_stupid_pushb_rotate_log(t_psdata *ps, t_stupid *stu
									,enum move move)
{
	char		*tmp;
	char		*str;
	char		*strp;

	if (!stu->i)
		return ;
	tmp = ps->log2;
	stu->in = (move == ra) ? (stu->i * 3) : (stu->i * 4);
	if (!(str = ft_strnew(stu->in)))
		ps_error(ps, 666);
	strp = str;
	ps->nb2 += stu->i;
	while (stu->in)
	{
		if (move == ra && ((stu->in -= 3) || 1))
			ft_memcpy(strp, " ra", 3);
		if (move == rra && ((stu->in -= 4) || 1))
			ft_memcpy(strp, " rra", 4);
		strp += (move == ra) ? 3 : 4;
	}
	ps_stupid_pushb_rotate_display(ps, stu , move);
	if (((*strp = '\0') || 1) && !ps->log2)
		ps->log2 = str;
	else
		ft_printf("%-!%s%s", &ps->log2, tmp, str);
}

void		ps_stupid_pushb_rotate(t_psdata *ps, t_stupid *stu
									,enum move move)
{
	t_psstack *stk;
	t_psstack *next;

	next = stu->s->n;
	stk = ps->st2a;
	stu->i = 0;
	ps->i = 0;
	while (stk->val != stu->s->val)
	{
		if (next && next->n && stk->val == next->val)
		{
			ps_stupid_pushb_rotate_log(ps, stu , move);
			if (ps->verb)
				ft_printf("[STUPID++] current is next: %d\n", next->val);
			stu->i = 0;
			ps->st2a = stk;
			ps->i++;
			stu->acount--;
			ps_move2(ps, pb);
			stk = ps->st2a;
			next = next->n;
		}
		else
			stk = ((++stu->i) && move == ra) ? stk->p : stk->n;
	}
	ps_stupid_pushb_rotate_log(ps, stu , move);
	ps->st2a = stk;
	if (++stu->first > 1)
	{
		if ((stu->i = ps->i) && ps->i > 1)
			while (ps->i--)
				ps_move2(ps, rb);
		ps_move2(ps, pb);
		if (stu->i && stu->i > 1)
			while (stu->i--)
				ps_move2(ps, rrb);
		if (ps->i == 1)
			ps_move2(ps, sb);
	}
	else
	{
		ps_move2(ps, pb);
		if (ps->i > 0)
			ps_move2(ps, rb);
	}
	stu->acount--;
	stu->i = 0;
	stk = ps->st2a;
	stu->s = next;
}

void		ps_stupid_pushb(t_psdata *ps, t_stupid *stu, t_psstack *s
						, t_psstack *x)
{
	while (s && s->n && (s->n)->n)
	{
		if (ps->verb)
			ft_printf("[STUPID++] search: %d\n", s->val);
		stu->ip = 0;
		x = ps->st2a;
		while (x->val != s->val && ++stu->ip)
			x = x->p;
		stu->in = (stu->ip) ? stu->acount - stu->ip : 0;
		ps_stupid_pushb_rotate(ps, stu, ((stu->ip <= stu->in) ? 5 : 8));
		s = stu->s;
	}
	if (ps->st2a->val > (ps->st2a->p)->val)
		ps_move2(ps, sa);
}
