/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:22:27 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/25 14:22:36 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	get_ants(t_fourm *fourm, char *line)
{
	get_next_line(0, &line);
	if (!(fourm->nb_fourmis = ft_atoi(line)))
	{
		ft_strdel(&line);
		error(fourm);
	}
	ft_strdel(&line);
}

static void	finish_fourm(t_fourm *fourm)
{
	t_room	*temp;
	int		i;

	i = 0;
	temp = NULL;
	if (fourm->room_list)
		fourm->start->next = fourm->room_list;
	temp = fourm->start;
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	temp->next = fourm->end;
	fourm->nb_pieces = i + 2;
}

void		fill_struct(t_fourm *fourm)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	get_ants(fourm, line);
	while (!(line = create_anthill(fourm, line)))
		i++;
	if (!fourm->start || !fourm->end)
		error(fourm);
	finish_fourm(fourm);
	get_tubes(fourm, line);
	generate_ants(fourm);
}
