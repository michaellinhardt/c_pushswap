/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_stupid_pushb.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:13:41 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/26 00:06:10 by mlinhard         ###   ########.fr       */
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

void		ps_stupid_pushb_rotate_log(t_psdata *ps, t_stupid *stu
									,enum move move)
{
	char		*tmp;
	char		*str;
	char		*strp;

	tmp = ps->log2; // retiens lancien log
	stu->in = (move == ra) ? (stu->i * 3) : (stu->i * 4); // calcule la taille du maloc
	if (!(str = ft_strnew(stu->in)))
		ps_error(ps, 666);
	strp = str;
	ft_printf("taille maloc du log: %d\n", stu->in);
	while (stu->in)
	{
		if (move == ra && ((stu->in -= 3) || 1))
			ft_memcpy(strp, " ra", 3);
		if (move == rra && ((stu->in -= 4) || 1))
			ft_memcpy(strp, " rra", 4);
		strp += (move == ra) ? 3 : 4;
	}
	*strp = '\0';
	ft_printf("ret: %s\n", str);
}

void		ps_stupid_pushb_rotate(t_psdata *ps, t_stupid *stu
									,enum move move)
{
	t_psstack *stk; // ptr utilisé pour parcourir la liste
	t_psstack *next; // ptr sur lelement next recherché


	// FONCTION APPELLé QUAND ON CONNAIS LA DIRECTION ET LELEMENT RECHERCHé
	next = stu->s->n; // ELEMENT SUIVANT DE LA SOLUTION
	stk = ps->st2a; // DEPART DE LA STACK
	stu->i = 0; // permet de compter le nombre de déplacement pour les log
	ft_printf("stk: %d, s: %d\n", stk->val, stu->s->val);
	while (stk->val != stu->s->val) // parcour tous les élément jusko recherché
	{
		ft_printf("eval: %d, next: %d, move: %d\n", stk->val, next->val, stu->i);
		if (next && stk->val == next->val) // la valeur actuel est le next recherché
		{
			ft_printf("élement recherché!\n");
			stu->acount--; // décrémente la taille de la stack a car on va faire un pushb
			ps_stupid_pushb_rotate_log(ps, stu , move); // on log la liste de déplacement
			// execute un move(pb)
			// rerégler stk sur ps->st2a
			next = next->n; // l'élément next étant trouvé, on cherche maintenatn le suivant
		}
		// déplace a gauche ou a droite la liste (selon le move demandé)
		// et incrémente stu->i pour compter les déplacement fais
		stk = ((++stu->i) && move == ra) ? stk->p : stk->n;
	}
	// ici on est arrivé à l'élément recherché, on peux le push
	// on change l'élément recherché
	stu->s = next;
}

void		ps_stupid_pushb(t_psdata *ps, t_stupid *stu, t_psstack *s
						, t_psstack *x)
{
	while (s && s->n) // BOUCLE SUR CHAQUE ELEM DE LA SOLUTION
	{
		stu->ip = 0;
		x = ps->st2a;
		while (x->val != s->val && ++stu->ip)
			x = x->p; // POSITION DE LELEMENT RECHERCHER DANS LA STACK
		// NOMBRE DE DEPLACEMENT DANS UN SENS ET DANS LAUTRE ->
		stu->in = (stu->ip) ? stu->acount - stu->ip : 0;
		// ps->i = (stu->ip <= stu->in) ? stu->ip : stu->in;
		// if (stu->ip <= stu->in) // MOVE RA DEMANDÉ STU->IP FOIS
		ft_printf("watch for: %d\n", s->val);
		ps_stack_print(ps, ps->st2a);
		// ICI ON CONNAIS LELEMENT RECHERCHé, AINSI QUE LA DIRECTION A PRENDRE
		ps_stupid_pushb_rotate(ps, stu, ((stu->ip <= stu->in) ? 5 : 8)); // 5 = enum move ra
		// else // MOVE RRA DEMANDÉ STU->IN FOIS
		// 	ps_stupid_rotate(ps, stu, x, 8); // 8 = enum move ra
		// ROTATION DE PILE B POUR REPLACER LES ELEMENT PRIS AU VOL

		// PUIS PUSHB L'ELEMENT INITIALEMENT RECHERCHÉ

		s = s->n;
	}
}

void		ps_stupid_pushb_backup(t_psdata *ps, t_stupid *stu, t_psstack *s
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
