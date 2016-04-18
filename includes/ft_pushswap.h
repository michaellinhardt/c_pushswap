/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:25:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/18 21:27:20 by mlinhard         ###   ########.fr       */
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
	int					i;
	struct s_psstack	*prev;
	struct s_psstack	*next;
}						t_psstack;

typedef struct			s_psdata
{
	int					opts;
	int					verb;
	int					col;
	int					count;
	char				cwhi[7];
	char				cyel[7];
	char				cblu[7];
	char				cred[7];
	char				*log1;
	char				*nb1;
	char				*log2;
	char				*nb2;
	t_psstack			*st1a;
	t_psstack			*st1b;
	t_psstack			*st2a;
	t_psstack			*st2b;
}						t_psdata;

void		ps_test_free(char **argv);

void		ps_error(t_psdata *ps, int er);

void		ps_parse_options(t_psdata *ps, char **argv);
void		ps_parse_array(t_psdata *ps, char **argv);

void		ps_stack_free(t_psdata *ps);

void		ps_stack_print(t_psdata *ps, t_psstack *root);
int			ps_verbose(t_psdata *ps, int msg);
void		ps_verbose2(t_psdata *ps, int msg);
void		ps_colors(t_psdata *ps);

void		ps_verbose_init(t_psdata *ps, char ret[101][512]);

void		ps_move1(t_psdata *ps, enum move move);

#endif
