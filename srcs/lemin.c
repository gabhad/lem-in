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

int	main(int argc, char **argv)
{
	t_fourm	*fourm;

	fourm = NULL;
	(void)argv;
	(void)argc;
/*	if (argc == 1)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}*/
	getdata(fourm);
	lemin_solver(fourm);
	clear_fourm(fourm);
	return (0);
}
