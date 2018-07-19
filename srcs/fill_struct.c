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
}

void		fill_struct(t_fourm *fourm)
{
	char	*line;
	int		i;
	t_room	*temp;

	line = NULL;
	i = 0;
	get_ants(fourm, line);
//	printf("fourmis = %d\n", fourm->nb_fourmis);
	while (create_anthill(fourm, line))
		i++;
	write(1, "tata\n", 5);
	if (!fourm->start || !fourm->end)
		error(fourm);
	temp = fourm->start;
	while (temp->next)
		temp = temp->next;
	temp->next = fourm->end;
	fourm->nb_pieces = i;
	get_tubes(fourm, line);
	generate_ants(fourm);
}
