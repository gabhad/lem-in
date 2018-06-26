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

# include "../libft/includes/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_room
{
	char			*name;
	char			*links;
	int				ant;
	int				x;
	int				y;
	struct s_room	*next;
}				t_room;

typedef struct s_ant
{
	char			*name;
	t_room			room;	
}				t_ant;

typedef struct s_fourm
{
	t_room			*start;
	t_room			*end;
	int				nb_fourmis;
	int				nb_pieces;
}				t_fourm;

void	error(t_fourm *fourm);
void	error_table(t_fourm *fourm);
void	getdata(char **param);
void	fill_struct(t_fourm *fourm);
int		create_anthill(t_fourm *fourm, char *line);
void	create_room(t_fourm *fourm, char *line);
void	clear_fourm(t_fourm *fourm);
int		check_table(char **table);

#endif