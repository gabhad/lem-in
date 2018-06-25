/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:35:19 by ghaddad           #+#    #+#             */
/*   Updated: 2018/06/25 17:35:20 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_table(char **table)
{
	int		i;

	i = 0;
	if (!table || !table[0] || !table[1] || !table[2] || table[3])
		return (0);
	/*while (tab[1][i] == '0')
		i++;
	if (tab[1][i] != '+' && (tab[1][i] < '0' || tab[1][i] > '9'))
		return (NULL);
	while (tab[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (NULL);
		i++;
	}
	if (ft_atoi(table[1]) < 0 || ft_atoi(table[2]) < 0)
		return (0);*/
	// verifier que les donnes envoyees pour les room sont bonnes
}
