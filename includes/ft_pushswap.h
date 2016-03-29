/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:25:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/03/29 06:40:58 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

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
	t_psstack			*st1;
	t_psstack			*st2;
}						t_psdata;

void		ps_test_free(char **argv);

void		ps_error(int er);

int			ps_parse_options(t_psdata *ps, char **argv);
int			ps_parse_array(t_psdata *ps, char **argv);

#endif
