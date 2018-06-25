/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_anthill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 15:05:34 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/25 15:05:35 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	clean_table(t_fourm *fourm, char **table, char *line)
{
	int		i;

	i = 0;
	while (table[i])
	{
		ft_strdel(&table[i]);
		i++;
	}
	free(table);
	ft_strdel(&line);
	error(fourm);
}

static void	initialize_start(t_fourm *fourm, char **param, char *line)
{
	char	**table;
	t_room	*start;

	ft_strdel(&line);
	if (!(get_next_line(0, &line)))
		error(fourm);
	table = ft_strsplit(line);
	if (!check_table(table))
		clean_table(fourm, table, line)
	if (!(start = (t_room*)malloc(sizeof(t_room))))
		clean_table(fourm, table, line)
}

static void	gerer_diese(t_fourm *fourm, char **param, char *line)
{
	if (line[1] != '#')
	{
		ft_strdel(&line);
		return ;
	}
	else
	{
		if (!ft_strcmp(line, "##start"))
			initialize_start(fourm, param, line);
		else if (!ft_strcmp(line, "##end"))
			initialize_end(fourm, param, line);
		else
		{
			ft_strdel(&line);
			error(fourm);
		}
	}
}

int			create_anthill(t_fourm *fourm, char **param, char *line)
{
	if (!(get_next_line(0, line)))
		error();
	if (line[0] == '#')
	{
		gerer_diese(fourm, param, line);
		return (1);
	}
}
