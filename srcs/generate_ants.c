/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 10:38:54 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/28 10:38:56 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_ant	*create_ant(t_fourm *fourm, int id)
{
	t_ant	*ant;

	if (!(ant = (t_ant*)malloc(sizeof(t_ant))))
		error(fourm);
	ant->id = id;
	ant->room = fourm->start;
	return (ant);
}

void			generate_ants(t_fourm *fourm)
{
	int		i;
	t_ant	*temp;

	i = 2;
	fourm->first_ant = create_ant(fourm, 1);
	temp = fourm->first_ant;
	while (i < (fourm->nb_fourmis + 1))
	{
		temp->next = create_ant(fourm, i);
		temp = temp->next;
		i++;
	}
	temp->next = NULL;
}
