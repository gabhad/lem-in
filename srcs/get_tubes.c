/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tubes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 08:10:36 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/28 08:10:37 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		gerer_diese(t_fourm *fourm, char *line)
{
	if (line[1] == '#')
	{
		write(1, "Unknown instruction\n", 20);
		ft_strdel(&line);
		error_table(fourm);
	}
	fourm->fourm = joinfree_space(fourm->fourm, line);
}

static void		new_room(t_fourm *f, t_tube *tube, t_room *room, char **table)
{
	t_room	*temp;

	tube->room1 = room;
	temp = f->start;
	while (ft_strcmp(table[1], temp->name) != 0)
		temp = temp->next;
	if (!temp || temp == room)
	{
		del_table(table);
		error(f);
	}
	tube->room2 = temp;
	tube->next_tube = NULL;
	del_table(table);
}

static t_tube	*check_liaison(t_fourm *fourm, char *line)
{
	t_room	*temp;
	t_tube	*tube;
	char	**table;

	if (!(tube = (t_tube*)malloc(sizeof(t_tube))))
		error(fourm);
	temp = fourm->start;
	table = ft_strsplit(line, '-');
	while (temp)
	{
		if (!ft_strcmp(table[0], temp->name))
		{
			new_room(fourm, tube, temp, table);
			return (tube);
		}
		else
			temp = temp->next;
	}
	write(1, "Unknown tube\n", 13);
	ft_strdel(&line);
	error_table(fourm);
	return (NULL);
}

void			get_tubes(t_fourm *fourm, char *line)
{
	t_tube	*temp;

	fourm->first_tube = check_liaison(fourm, line);
	temp = fourm->first_tube;
	fourm->fourm = joinfree_space(fourm->fourm, line);
	while (get_next_line(0, &line))
	{
		if (line[0] == '#')
			gerer_diese(fourm, line);
		else
		{
			temp->next_tube = check_liaison(fourm, line);
			temp = temp->next_tube;
			fourm->fourm = joinfree_space(fourm->fourm, line);
		}
	}
	temp = fourm->first_tube;
	while (temp)
	{
		if (temp->room1 == fourm->end || temp->room2 == fourm->end)
			return ;
		temp = temp->next_tube;
	}
	error(fourm);
}
