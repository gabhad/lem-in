/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 15:49:28 by ghaddad           #+#    #+#             */
/*   Updated: 2018/07/05 15:49:30 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
 
static void	reverse_path(t_fourm *fourm)
{
	t_room	*newlist;
	t_room	*next;

	newlist = NULL;
	while (fourm->shortest_path)
	{
		next = fourm->shortest_path->next;
		fourm->shortest_path->next = newlist;
		newlist = fourm->shortest_path;
		fourm->shortest_path = next;
	}
	fourm->shortest_path = newlist;
}

void		set_path(t_fourm *fourm)
{
	t_room	*path;
	t_tube	*tube;

	fourm->shortest_path = fourm->end;
	path = fourm->shortest_path;
	tube = fourm->first_tube;
	while (path != fourm->start)
	{
		while (path != tube->room1 && path != tube->room2)
			tube = tube->next_tube;
		if (path == tube->room1 
			&& path->distance == tube->room2->distance + 1)
			path->next = tube->room2;
		else if ((path == tube->room2 
			&& path->distance == tube->room1->distance + 1))
			path->next = tube->room1;
		path = path->next;
	}
	reverse_path(fourm);
}