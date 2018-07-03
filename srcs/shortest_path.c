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

#include "../includes/lemin.h"

static void	continue_path(t_fourm *fourm, t_room *room)
{
	(void)fourm;
	(void)room;
}

static void	find_path(t_fourm *fourm, t_room *room)
{
	t_tube	*tube;

	room->distance = 1;
	tube = fourm->first_tube;
	while (tube)
	{
		while (tube->room1 != room && tube->room2 != room)
			tube = tube->next_tube;
		if (tube->room1 == room && (tube->room2->distance == -1 
									|| tube->room2->distance > 1))
			continue_path(fourm, tube->room2);
		else if ((tube->room2 == room && (tube->room1->distance == -1 
									|| tube->room1->distance > 1)))
			continue_path(fourm, tube->room1);
	}
}

void		shortest_path(t_fourm *fourm)
{
	t_tube	*tube;
	t_room	*temp;

	temp = fourm->start;
	tube = fourm->first_tube;
	while (tube)
	{
		while (tube->room1 != temp && tube->room2 != temp)
			tube = tube->next_tube;
		if (fourm->start == tube->room1)
			find_path(fourm, tube->room1);
		else if (fourm->start == tube->room2)
			find_path(fourm, tube->room2);
	}
}
