/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joinfree_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 08:48:21 by ghaddad           #+#    #+#             */
/*   Updated: 2018/08/09 08:48:37 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	*joinfree_space(char *s1, char *s2)
{
	s2 = ft_strjoinfree(s2, ft_strdup("\n"));
	s1 = ft_strjoinfree(s1, s2);
	return (s1);
}
