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
	while (ft_strcmp(temp->room->name, room->name))
		temp = temp->next;
	temp->room->ant = 0;
	temp->room = room->next;
	temp->room->ant = 1;
	return (temp->id);
}

static void	move_ants(t_fourm *fourm)
{
	t_path	*temp;
	t_ant	*tempant;
	int		antno;

	temp = fourm->shortest_path->next;
	while (!temp->room->ant)
		temp = temp->next;
	antno = next_ant(fourm, temp->room);
	tempant = fourm->first_ant;
	ft_printf("L%d-%s", tempant->id, tempant->room->name);
	while (temp->next && temp->next->room->ant)
	{
		ft_printf(" ");
		temp = temp->next;
		antno = next_ant(fourm, temp->room);
		tempant = fourm->first_ant;
		ft_printf("L%d-%s", tempant->id, tempant->room->name);
	}
	if (!temp->next || !temp->next->room->ant)
	{
		ft_printf("\n");
		move_ants(fourm);
	}
}

void		direct_ants(t_fourm *fourm)
{
	while (fourm->end->ant != fourm->nb_fourmis)
		move_ants(fourm);
}
