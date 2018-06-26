/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 13:38:19 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/25 13:38:20 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void		error_table(t_fourm *fourm)
{
	if (fourm)
		clear_fourm(fourm);
	exit(0);
}

void		error(t_fourm *fourm)
{
	if (fourm)
		clear_fourm(fourm);
	write(1, "ERROR\n", 6);
	exit(0);
}
