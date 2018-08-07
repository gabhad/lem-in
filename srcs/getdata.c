/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:10:40 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/25 14:10:41 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_fourm	*getdata(t_fourm *fourm)
{
	if (!(fourm = (t_fourm*)malloc(sizeof(t_fourm))))
		error(fourm);
	fourm->start = NULL;
	fourm->end = NULL;
	fourm->room_list = NULL;
	fourm->first_tube = NULL;
	fourm->first_ant = NULL;
	fourm->shortest_path = NULL;
	fourm->fourm = NULL;
	fill_struct(fourm);
	return (fourm);
}
