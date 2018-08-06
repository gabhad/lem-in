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

#include "lemin.h"

static int		path_loop(t_path *path, t_tube *tube)
{
	while (path->room != tube->room1
			&& path->room != tube->room2)
		tube = tube->next_tube;
	while (tube)
	{
		if (path->room == tube->room1
			&& path->room->distance == tube->room2->distance + 1)
		{
			path->next->room = tube->room2;
			return (1);
		}
		else if (path->room == tube->room2
			&& path->room->distance == tube->room1->distance + 1)
		{
			path->next->room = tube->room1;
			return (1);
		}
		else
			tube = tube->next_tube;
	}
	return (0);
}

static t_path	*create_path(t_fourm *fourm)
{
	t_path	*path;

	if (!(path = (t_path *)malloc(sizeof(t_path))))
		error(fourm);
	path->room = NULL;
	path->next = NULL;
	return (path);
}

void			set_path(t_fourm *fourm)
{
	t_path	*path;
	t_tube	*tube;

	path = create_path(fourm);
	fourm->shortest_path = path;
	path->room = fourm->end;
	tube = fourm->first_tube;
	while (path->room != fourm->start)
	{
		path->next = create_path(fourm);
		while (!path_loop(path, tube))
			tube = tube->next_tube;
		path = path->next;
		tube = fourm->first_tube;
	}
}
