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

typedef struct	s_room
{
	char			*name;
	char			*links;
	int				ant;
	int				x;
	int				y;
	int				distance;
	struct s_room	*next;
	struct s_room	*prev;
}				t_room;

typedef struct	s_ant
{
	int				id;
	t_room			*room;
	struct s_ant	*next;
}				t_ant;

typedef struct	s_tube
{
	t_room			*room1;
	t_room			*room2;
	struct s_tube	*next_tube;
}				t_tube;

typedef struct	s_path
{
	t_room			*room;
	struct s_path	*next;
}				t_path;

typedef struct	s_fourm
{
	t_room			*start;
	t_room			*end;
	t_room			*room_list;
	t_tube			*first_tube;
	t_ant			*first_ant;
	t_path			*shortest_path;
	int				nb_fourmis;
	int				nb_pieces;
}				t_fourm;

void			error(t_fourm *fourm);
void			error_table(t_fourm *fourm);
t_fourm			*getdata(t_fourm *fourm);
void			fill_struct(t_fourm *fourm);
char			*create_anthill(t_fourm *fourm, char *line);
void			create_room(t_fourm *fourm, char *line);
void			clear_fourm(t_fourm *fourm);
int				check_table(char **table);
void			del_table(char **tab);
void			get_tubes(t_fourm *fourm, char *line);
void			generate_ants(t_fourm *fourm);
t_fourm			*lemin_solver(t_fourm *fourm);
void			shortest_path(t_fourm *fourm);
void			clean_table(t_fourm *fourm, char **table, char *line);
void			set_path(t_fourm *fourm);
void			direct_ants(t_fourm *fourm);

#endif
