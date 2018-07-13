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

#include "../includes/lemin.h"

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
	while (!temp->next_tube)
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
	if (room->links)
		ft_strdel(&(room->links));
	free(room);
}

void		clear_fourm(t_fourm *fourm)
{
	t_room	*temp;
	t_room	*temp_next;

	temp_next = NULL;
	if (fourm->start)
	{
		temp = fourm->start;
		while (temp->next)
		{
			temp_next = temp->next;
			clear_room(temp);
			temp = temp_next;
		}
		clear_room(temp);
	}
	clear_tubes(fourm);
	clear_ants(fourm);
	free(fourm);
}
