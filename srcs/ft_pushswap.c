/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 04:38:09 by mlinhard          #+#    #+#             */
/*   Updated: 2016/03/29 06:44:24 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_pushswap.h"

void		ps_test_free(char **argv)
{
	int i = -1;
	while (argv[++i])
		ft_strdel(&argv[i]);
	ft_memdel((void **)&argv);
}

void		ps_error(int er)
{
	if (er == 1)
		ft_putstr("Error: Nombre d'argument(s) invalide!\n");
	if (er == 2)
		ft_putstr("Error: Option(s) invalide.\n");
	if (er == 3)
		ft_putstr("Error: Argument(s) invalide.\n");
	exit(1);
}

int			main(int argc, char **argv)
{
	t_psdata	ps;

argv = ft_strsplit("a.out -vc 3 4 5 6 8", ' '); argc = 2;

	ft_bzero((void **)&ps, sizeof(t_psdata));
	if (argc == 1)
		ps_error(1);
	if (ps_parse_options(&ps, argv))
		ps_error(2);
	if (ps_parse_array(&ps, argv))
		ps_error(3);

ps_test_free(argv);

	return (0);
}

