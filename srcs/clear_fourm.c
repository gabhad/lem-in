/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_fourm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:18:34 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/25 17:18:37 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	clear_room(t_room *room)
{
	if (room->name)
		ft_strdel(&(room->name));
	if (room->links)
		ft_strdel(&(room->links));
	free(room);
}

void		clear_fourm(t_fourm *fourm)
{
	int i;

	i = 0;
	if (fourm->start)
		clear_room(fourm->start);
	if (fourm->end)
		clear_room(fourm->end);
	while (fourm->room[i])
	{
		clear_room(fourm->room[i]);
		i++;
	}
	free(fourm);
}