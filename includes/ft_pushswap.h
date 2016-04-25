/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:25:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/25 09:55:28 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

# include "libft.h"
# include <stdlib.h>
# include <limits.h>

enum move { sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr };

typedef struct			s_stupid
{
	int					i;
	int					b;
	int					next;
	int					acount;
	int					in;
	int					ip;
	struct s_psstack	*s;
}						t_stupid;

typedef struct			s_stupid2
{
	int					in;
	int					ip;
	struct s_psstack	*s;
}						t_stupid2;

typedef struct			s_psstack
{
	int					stop;
	int					val;
	int					i;
	struct s_psstack	*p;
	struct s_psstack	*n;
}						t_psstack;

typedef struct			s_psdata
{
	int					i;
	int					min;
	int					max;
	int					count;
	int					opts;
	int					verb;
	int					col;
	char				cwhi[7];
	char				cyel[7];
	char				cblu[7];
	char				cred[7];
	char				*log1;
	char				*log2;
	char				*log3;
	char				*log4;
	char				*log5;
	int					nb1;
	int					nb2;
	int					nb3;
	int					nb4;
	int					nb5;
	t_psstack			*s;
	t_psstack			*st1a;
	t_psstack			*st1b;
	t_psstack			*st2a;
	t_psstack			*st2b;
	t_psstack			*st3a;
	t_psstack			*st3b;
	t_psstack			*st4a;
	t_psstack			*st4b;
	t_psstack			*st5a;
	t_psstack			*st5b;
}						t_psdata;

void		ps_error(t_psdata *ps, int er);

void		ps_parse_options(t_psdata *ps, char **argv);
void		ps_parse_array(t_psdata *ps, char **argv);
void		ps_parse_double(t_psdata *ps);

void		ps_stack_free(t_psdata *ps);

void		ps_stack_print(t_psdata *ps, t_psstack *root);
int			ps_verbose(t_psdata *ps, int msg);
void		ps_verbose2(t_psdata *ps, int msg);
void		ps_colors(t_psdata *ps);

void		ps_verbose_init(char ret[101][512]);

void		ps_move1(t_psdata *ps, enum move move);
void		ps_move2(t_psdata *ps, enum move move);
void		ps_move3(t_psdata *ps, enum move move);
int			ps_move4(t_psdata *ps, enum move move);
int			ps_move5(t_psdata *ps, enum move move);

int			ps_claptrap(t_psdata *ps);

int			ps_stupid(t_psdata *ps);
void		ps_stupid_pushb(t_psdata *ps, t_stupid *stu, t_psstack *s
						, t_psstack *x);
int			ps_stupid2(t_psdata *ps);

int			ps_solv(t_psdata *ps);
int			ps_issolved(t_psdata *ps, t_psstack *x);

int			ps_bubble1(t_psdata *ps);
int			ps_bubble2(t_psdata *ps);
int			ps_bubble3(t_psdata *ps);

#endif
