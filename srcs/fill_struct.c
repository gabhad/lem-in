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

static void	get_ants(t_fourm *fourm, char **param, char *line)
{
	get_next_line(0, &line);
	if (!(fourm->nb_fourmis = ft_atoi(line)))
	{
		ft_strdel(&line);
		error(fourm);
	}
	ft_strdel(&line);
}

void		fill_struct(t_fourm *fourm, char **param)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	get_ants(fourm, param, line);
	while (create_anthill(fourm, param, line))
		i++;
}
