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

static int	correct_table(char *str)
{
	int		i;

	i = 0;
	while (str[i] == '0')
		i++;
	if (i > 0 && !str[i])
		return (1);
	if (str[i] != '+' && (str[i] < '0' || str[i] > '9'))
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int			check_table(char **table)
{
	int		i;

	i = 0;
	if (!table || !table[0] || !table[1] || !table[2] || table[3])
	{
		write(1, "Parametres incorrects\n", 22);
		return (0);
	}
	if (table[0][0] == 'L')
	{
		write(1, "Un nom de piece ne peut pas commencer par 'L'\n", 46);
		return (0);
	}
	if (!correct_table(table[1]) || !correct_table(table[2]))
	{
		write(1, "Merci de rentrer des coordonnees valides\n", 41);
		return (0);
	}
	if (ft_atoi(table[1]) < 0 || ft_atoi(table[2]) < 0)
	{
		write(1, "Merci de rentrer des coordonnees valides\n", 41);
		return (0);
	}
	return (1);
}
