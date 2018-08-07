/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_solver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 11:02:13 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/28 11:02:14 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_fourm	*lemin_solver(t_fourm *fourm)
{
	shortest_path(fourm);
	set_path(fourm);
	ft_printf("%s\n", fourm->fourm);
	direct_ants(fourm);
	return (fourm);
}
