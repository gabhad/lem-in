/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 10:41:18 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/26 10:41:25 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	create_room(t_fourm *fourm, char *line)
{
	t_room	*room;
	t_room	*temp;
	char	**table;

	table = ft_strsplit(line, ' ');
	if (!check_table(table))
	{
		clean_table(fourm, table, line);
		error_table(fourm);
	}
	if (!(room = (t_room*)malloc(sizeof(t_room))))
		clean_table(fourm, table, line);
	room->name = ft_strdup(table[0]);
	room->x = ft_atoi(table[1]);
	room->y = ft_atoi(table[2]);
	room->distance = -1;
	temp = fourm->start;
	while (temp->next)
		temp = temp->next;
	room = temp->next;
	room->next = NULL;
}
