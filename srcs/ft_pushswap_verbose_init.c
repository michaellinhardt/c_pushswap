/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_verbose_init.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 04:38:09 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/25 00:24:19 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ps_verbose_init(char ret[101][512])
{
	ft_memcpy(ret[1], "[ERROR] too few argument(s)\n", 28);
	ft_memcpy(ret[2], "[ERROR] bad option found, use -h for help\n", 42);
	ft_memcpy(ret[3], "[ERROR] only int are allowed\n", 29);
	ft_memcpy(ret[4], "[ERROR] duplicated value\n", 25);
	ft_memcpy(ret[10], "[PARSE] verbose activated\n", 31);
	ft_memcpy(ret[11], "[PARSE] color activated\n", 31);
	ft_memcpy(ret[20], "[ALGO] run algo stupid++..\n", 27);
	ft_memcpy(ret[21], "[ALGO] run algo bubble1..\n", 26);
	ft_memcpy(ret[22], "[ALGO] run algo bubble2..\n", 26);
	ft_memcpy(ret[23], "[ALGO] run algo stupid..\n", 27);
	ft_memcpy(ret[24], "[ALGO] run algo bubble3..\n", 26);
	ft_memcpy(ret[30], "[STUPID] building push order\n", 29);
	ft_memcpy(ret[31], "[STUPID] push all value to B\n", 29);
	ft_memcpy(ret[32], "[STUPID] push back to A\n", 24);
	ft_memcpy(ret[33], "[BUBBLE3] aborted, too many moves!\n", 35);
	ft_memcpy(ret[34], "[BUBBLE1] aborted, too many moves!\n", 35);
	ft_memcpy(ret[35], "[BUBBLE2] aborted, too many moves!\n", 35);
	ft_memcpy(ret[100], "[ERROR] cant malloc\n", 20);
}
