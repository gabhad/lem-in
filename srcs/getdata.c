/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:10:40 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/25 14:10:41 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	getdata(t_fourm	*fourm)
{
	t_fourm		*fourm;

	if (!(fourm = (t_fourm*)malloc(sizeof(t_fourm))))
		error(fourm);
	fill_struct(fourm);
}
