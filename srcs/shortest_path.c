/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 11:32:28 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/28 11:32:30 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	valid_conditions(t_room *room1, t_room *room2, t_room *room)
{
	if (room1 == room &&
			(room2->distance > room->distance + 1 ||
				room2->distance == -1))
		return (1);
	else
		return (0);
}

static int	increase_distance(t_fourm *fourm, t_room *room1, t_room *room2)
{
	room1->distance = room2->distance + 1;
	if (room1 != fourm->end)
		find_path(fourm, room1);
	return (1);
}

int			find_path(t_fourm *fourm, t_room *room)
{
	t_tube	*tube;

	tube = fourm->first_tube;
	while (tube && tube->room1 != room && tube->room2 != room)
		tube = tube->next_tube;
	if (!tube)
		error(fourm);
	while (tube)
	{
		if (valid_conditions(tube->room1, tube->room2, room))
		{
			if (tube->room2 == fourm->end)
				return (increase_distance(fourm, fourm->end, room));
			increase_distance(fourm, tube->room2, room);
		}
		else if (valid_conditions(tube->room2, tube->room1, room))
		{
			if (tube->room1 == fourm->end)
				return (increase_distance(fourm, fourm->end, room));
			increase_distance(fourm, tube->room1, room);
		}
		tube = tube->next_tube;
	}
	return (0);
}

void		shortest_path(t_fourm *fourm)
{
	t_tube	*tube;

	tube = fourm->first_tube;
	while (tube->room1 != fourm->start && tube->room2 != fourm->start)
		tube = tube->next_tube;
	if (!tube)
		error(fourm);
	while (tube)
	{
		if (fourm->start == tube->room1 && tube->room2->distance == -1)
		{
			tube->room2->distance = 1;
			find_path(fourm, tube->room2);
		}
		else if (fourm->start == tube->room2 && tube->room1->distance == -1)
		{
			tube->room1->distance = 1;
			find_path(fourm, tube->room1);
		}
		tube = tube->next_tube;
	}
}
