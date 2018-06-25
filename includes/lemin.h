/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 10:47:44 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/25 10:47:46 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../includes/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_room
{
	char			*name;
	char			*links;
	int				ant;
	int				x;
	int				y;
}				t_room;

typedef struct s_ant
{
	char			*name;
	t_room			room;	
}				t_ant;

typedef struct s_fourm
{
	s_room			*start;
	s_room			*end;
	s_room			**room;
	int				nb_fourmis;
	int				nb_pieces;
}				t_fourm;

void	error(t_fourm *fourm);
void	getdata(char **param);
void	fill_struct(t_fourm *fourm, char **param);
int		create_anthill(t_fourm *fourm, char **param, char *line);
void	clear_fourm(t_fourm *fourm);

#endif