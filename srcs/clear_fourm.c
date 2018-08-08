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

static void	clear_path(t_fourm *fourm)
{
	t_path	*temp;
	t_path	*tempnext;

	if (!fourm->shortest_path)
		return ;
	temp = fourm->shortest_path;
	while (temp->next)
	{
		tempnext = temp->next;
		free(temp);
		temp = temp->next;
	}
	free(temp);
}

static void	clear_ants(t_fourm *fourm)
{
	t_ant	*temp;
	t_ant	*tempnext;

	if (!fourm->first_ant)
		return ;
	temp = fourm->first_ant;
	while (temp->next)
	{
		tempnext = temp->next;
		free(temp);
		temp = temp->next;
	}
	free(temp);
}

static void	clear_tubes(t_fourm *fourm)
{
	t_tube	*temp;
	t_tube	*tempnext;

	if (!fourm->first_tube)
		return ;
	temp = fourm->first_tube;
	while (temp->next_tube)
	{
		tempnext = temp->next_tube;
		free(temp);
		temp = temp->next_tube;
	}
	free(temp);
}

static void	clear_room(t_room *room)
{
	if (room->name)
		ft_strdel(&(room->name));
	free(room);
}

void		clear_fourm(t_fourm *fourm)
{
	t_room	*temp;
	t_room	*temp_next;

	temp = NULL;
	temp_next = NULL;
	if (fourm->start)
		temp = fourm->start;
	else if (fourm->room_list)
		temp = fourm->room_list;
	if (temp && temp->next)
		while (temp->next)
		{
			temp_next = temp->next;
			clear_room(temp);
			temp = temp_next;
		}
	clear_room(temp);
	if (fourm->end)
		clear_room(fourm->end);
	clear_tubes(fourm);
	clear_ants(fourm);
	clear_path(fourm);
	ft_strdel(&fourm->fourm);
	free(fourm);
}
