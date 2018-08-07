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
	line = ft_strjoinfree(line, ft_strdup("\n"));
	fourm->fourm = ft_strjoinfree(fourm->fourm, line);
}

static void		new_room(t_fourm *fourm, t_tube *tube, t_room *room, char *line)
{
	t_room	*temp;

	temp = room->next;
	while (!ft_strstr(line, temp->name))
		temp = temp->next;
	if (!temp)
		error(fourm);
	tube->room2 = temp;
}

static t_tube	*check_liaison(t_fourm *fourm, char *line)
{
	t_room	*temp;
	t_tube	*tube;

	if (!(tube = (t_tube*)malloc(sizeof(t_tube))))
		error(fourm);
	temp = fourm->start;
	while (temp->next)
	{
		if (ft_strstr(line, temp->name))
		{
			tube->room1 = temp;
			new_room(fourm, tube, temp, line);
			tube->next_tube = NULL;
			return (tube);
		}
		else
			temp = temp->next;
	}
	write(1, "Unknown tube\n", 13);
	line = ft_strjoinfree(line, ft_strdup("\n"));
	fourm->fourm = ft_strjoinfree(fourm->fourm, line);
	error_table(fourm);
	return (NULL);
}

void			get_tubes(t_fourm *fourm, char *line)
{
	t_tube	*temp;

	fourm->first_tube = check_liaison(fourm, line);
	temp = fourm->first_tube;
	line = ft_strjoinfree(line, ft_strdup("\n"));
	fourm->fourm = ft_strjoinfree(fourm->fourm, line);
	while (get_next_line(0, &line))
	{
		if (line[0] == '#')
			gerer_diese(fourm, line);
		else
		{
			temp->next_tube = check_liaison(fourm, line);
			temp = temp->next_tube;
			line = ft_strjoinfree(line, ft_strdup("\n"));
			fourm->fourm = ft_strjoinfree(fourm->fourm, line);
		}
	}
}
