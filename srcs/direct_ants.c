/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 08:58:26 by ghaddad           #+#    #+#             */
/*   Updated: 2018/07/13 08:58:30 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int	next_ant(t_fourm *fourm, t_room *room)
{
	t_ant	*temp;

	temp = fourm->first_ant;
	while (ft_strcmp(temp->room, room->name))
		temp = temp->next;
	return (temp->id);
}

static void	move_ants(t_fourm *fourm)
{
	t_list	*temp;
	int		antno;

	temp = shortest_path->next;
	while (!temp->content->ant)
		temp = temp->next;
	antno = next_ant(fourm, temp->content);
}

void	direct_ants(t_fourm *fourm)
{
	while (fourm->end->ant != fourm->nb_fourmis)
	{
		move_ants(fourm);
		

	}
}
