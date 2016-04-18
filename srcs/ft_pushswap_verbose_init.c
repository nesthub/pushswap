/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_verbose_init.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 04:38:09 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/17 19:53:24 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ps_verbose_init(t_psdata *ps, char ret[101][512])
{
	ft_memcpy(ret[1], "[ERROR] too few argument(s)\n", 28);
	ft_memcpy(ret[2], "[ERROR] bad option found, use -h for help\n", 42);
	ft_memcpy(ret[3], "[ERROR] only int are allowed\n", 29);
	ft_memcpy(ret[4], "[ERROR] duplicated value\n", 25);

	ft_memcpy(ret[10], "[PARSE] verbose activated\n", 31);
	ft_memcpy(ret[11], "[PARSE] color activated\n", 31);

	ft_memcpy(ret[100], "[ERROR] cant malloc\n", 20);
}