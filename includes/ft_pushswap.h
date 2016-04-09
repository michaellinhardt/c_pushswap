/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:25:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/09 07:35:42 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

# include "libft.h"
# include <stdlib.h>
# include <limits.h>

enum move { sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr };

typedef struct		s_psstack
{
	int					val;
	struct s_psstack	*prev;
	struct s_psstack	*next;
}						t_psstack;

typedef struct			s_psdata
{
	int					opts;
	int					verb;
	int					col;
	int					count;
	int					nbmove;
	int					i;
	int					j;
	t_psstack			*st1;
	t_psstack			*st2;
	t_psstack			*st3;
}						t_psdata;

void		ps_test_free(char **argv);

void		ps_error(t_psdata *ps, int er);

void		ps_parse_options(t_psdata *ps, char **argv);
void		ps_parse_array(t_psdata *ps, char **argv);

void		ps_stack_add(t_psstack **root, int where, int val);
void		ps_stack_del(t_psstack **root, int where);
void		ps_stack_changelist(t_psstack **src, int srcwhere, t_psstack **dst
						, int dstwhere);

void		ps_stack_free(t_psdata *ps);

void		ps_stack_print_full(t_psstack *root);

void		ps_stack_move(t_psdata *ps, enum move move);

void		ps_presolve_add(t_psdata *ps, int val);

int			ps_verbose(t_psdata *ps, int msg);
void		ps_verbose2(t_psdata *ps, int msg);

#endif
