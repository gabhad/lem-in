/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 13:17:57 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/25 13:18:00 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	lemin(t_fourm *fourm)
{
	fourm = getdata(fourm);
	fourm = lemin_solver(fourm);
	clear_fourm(fourm);
}

int	main(int argc, char **argv)
{
	t_fourm	*fourm;

	fourm = NULL;
	(void)argv;
	(void)argc;
	lemin(fourm);
	return (0);
}
