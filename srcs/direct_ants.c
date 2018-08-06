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

#include "lemin.h"

static int	next_ant(t_fourm *fourm, t_path *path)
{
	t_ant	*temp;
	t_path	*previous;

	previous = fourm->shortest_path;
	while (previous->next != path)
		previous = previous->next;
	temp = fourm->first_ant;
	while (ft_strcmp(temp->room->name, path->room->name))
		temp = temp->next;
	temp->room->ant--;
	temp->room = previous->room;
	temp->room->ant++;
	return (temp->id);
}

static void	move_ants(t_fourm *fourm)
{
	t_path	*temp;
	t_ant	*tempant;
	int		antno;

	temp = fourm->shortest_path->next;
	while (temp->room->ant == 0)
		temp = temp->next;
	antno = next_ant(fourm, temp);
	tempant = fourm->first_ant;
	ft_printf("L%d-%s", tempant->id, tempant->room->name);
	while (temp->next && temp->next->room->ant)
	{
		ft_printf(" ");
		temp = temp->next;
		antno = next_ant(fourm, temp);
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
