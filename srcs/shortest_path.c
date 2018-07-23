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

static t_room	*get_next_room(t_tube *tube, t_room *room)
{
	t_room	*temp;

	printf("abc\n");
	if (room == tube->room1)
		temp = tube->room2;
	else if (room == tube->room2)
		temp = tube->room1;
	else
		return (NULL);
	if (temp->distance == -1 || temp->distance > room->distance + 1)
		return (temp);
	else
		return (NULL);
}

static void		continue_path(t_fourm *fourm, t_room *room)
{
	t_tube	*tube;
	t_room	*temp;
	t_room	*tempnext;

	printf("tutu\n");
	tube = fourm->first_tube;
	temp = room;
	tempnext = temp;
	while (tube && temp != fourm->end)
	{
		while (tube->room1 != room && tube->room2 != room)
			tube = tube->next_tube;
		if ((tempnext = get_next_room(tube, temp)))
			tempnext->distance = temp->distance + 1;
		if (tempnext != temp)
			tube = fourm->first_tube;
		else
			tube = tube->next_tube;
		temp = tempnext;
		if (temp == fourm->end)
			temp = fourm->start;
	}
	//donner condition de retour en arriere pour aller verifier les autres chemins
}

static void		find_path(t_fourm *fourm, t_room *room)
{
	t_tube	*tube;

	tube = fourm->first_tube;
	while (tube)
	{
		while (tube->room1 != room && tube->room2 != room)
			tube = tube->next_tube;
		if (tube->room1 == room && (tube->room2->distance == -1
									|| tube->room2->distance > 1))
		{
			tube->room2->distance = tube->room1->distance + 1;
			continue_path(fourm, tube->room2);
		}
		else if ((tube->room2 == room && (tube->room1->distance == -1
									|| tube->room1->distance > 1)))
		{
			tube->room1->distance = tube->room2->distance + 1;
			continue_path(fourm, tube->room1);
		}
		else
			tube = tube->next_tube;
	}
}

void			shortest_path(t_fourm *fourm)
{
	t_tube	*tube;

	tube = fourm->first_tube;
	while (tube->room1 != fourm->start && tube->room2 != fourm->start)
		tube = tube->next_tube;
	if (!tube)
		error(fourm);
	if (fourm->start == tube->room1)
	{
		tube->room2->distance = 1;
		find_path(fourm, tube->room2);
	}
	else if (fourm->start == tube->room2)
	{
		tube->room1->distance = 1;
		find_path(fourm, tube->room1);
	}
}
