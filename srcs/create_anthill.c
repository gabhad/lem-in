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

void		clean_table(t_fourm *fourm, char **table, char *line)
{
	int		i;

	i = 0;
	while (table[i])
	{
		ft_strdel(&table[i]);
		i++;
	}
	free(table);
	(void)fourm;
	ft_strdel(&line);
}

static void	initialize_end(t_fourm *fourm, char *line)
{
	char	**table;
	t_room	*end;

	fourm->fourm = joinfree_space(fourm->fourm, line);
	if (get_next_line(0, &line) < 1)
		error(fourm);
	table = ft_strsplit_whitespaces(line);
	if (!check_table(table))
	{
		clean_table(fourm, table, line);
		error_table(fourm);
	}
	if (!(end = (t_room*)malloc(sizeof(t_room))))
		clean_table(fourm, table, line);
	end->name = ft_strdup(table[0]);
	end->x = ft_atoi(table[1]);
	end->y = ft_atoi(table[2]);
	fourm->end = end;
	end->next = NULL;
	end->distance = -1;
	end->ant = 0;
	del_table(table);
	fourm->fourm = joinfree_space(fourm->fourm, line);
}

static void	initialize_start(t_fourm *fourm, char *line)
{
	char	**table;
	t_room	*start;

	fourm->fourm = joinfree_space(fourm->fourm, line);
	if (get_next_line(0, &line) < 1)
		error(fourm);
	table = ft_strsplit_whitespaces(line);
	if (!check_table(table))
	{
		clean_table(fourm, table, line);
		error_table(fourm);
	}
	if (!(start = (t_room*)malloc(sizeof(t_room))))
		clean_table(fourm, table, line);
	start->name = ft_strdup(table[0]);
	start->x = ft_atoi(table[1]);
	start->y = ft_atoi(table[2]);
	fourm->start = start;
	start->next = NULL;
	start->distance = 0;
	del_table(table);
	fourm->fourm = joinfree_space(fourm->fourm, line);
}

static void	gerer_diese(t_fourm *fourm, char *line)
{
	if (line[1] != '#')
	{
		fourm->fourm = joinfree_space(fourm->fourm, line);
		return ;
	}
	else
	{
		if (!ft_strcmp(line, "##start"))
			initialize_start(fourm, line);
		else if (!ft_strcmp(line, "##end"))
			initialize_end(fourm, line);
		else
		{
			fourm->fourm = joinfree_space(fourm->fourm, line);
			return ;
		}
	}
}

char		*create_anthill(t_fourm *fourm, char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (get_next_line(0, &line) < 1)
		error(fourm);
	if (line[0] == '#')
	{
		gerer_diese(fourm, line);
		return (NULL);
	}
	while (line[i])
	{
		if (line[i++] == ' ')
			j++;
	}
	if (j >= 2)
	{
		create_room(fourm, line);
		fourm->fourm = joinfree_space(fourm->fourm, line);
		return (NULL);
	}
	return (line);
}
