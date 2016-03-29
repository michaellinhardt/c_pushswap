/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:25:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/03/29 11:52:17 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct		s_psstack
{
	int					id;
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
	t_psstack			*st1;
	t_psstack			*st2;
	t_psstack			*st3;
}						t_psdata;

void		ps_test_free(char **argv);

void		ps_error(t_psdata *ps, int er);

void		ps_parse_options(t_psdata *ps, char **argv);
void		ps_parse_array(t_psdata *ps, char **argv);

void		ps_stack_add(t_psstack **root, int where, int id, int val);
void		ps_stack_solve(t_psdata *ps, t_psstack **root, int id, int val);

void		ps_stack_free(t_psdata *ps);

void		ps_stack_print_full(t_psstack *root);

#endif
