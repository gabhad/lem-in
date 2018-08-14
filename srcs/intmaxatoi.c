/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:29:35 by ghaddad           #+#    #+#             */
/*   Updated: 2018/08/14 14:22:04 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	big_number(const char *str)
{
	char	*string;
	int		i;
	int		n;

	string = ft_strdup(str);
	i = 0;
	n = 0;
	if (str[0] == '-')
		i++;
	while (string[i] == '0')
		i++;
	if (ft_strlen(string) - i > 11)
		n = 1;
	ft_strdel(&string);
	return (n);
}

intmax_t	push_swap_atoi(const char *str)
{
	intmax_t		i;
	unsigned int	n;
	unsigned int	t;

	i = 0;
	n = 0;
	if (big_number(str))
		return (2147483648);
	while (str[n] == ' ' || str[n] == '\n' || str[n] == '\t'
			|| str[n] == '\v' || str[n] == '\r' || str[n] == '\f')
		n++;
	t = n;
	if (str[n] == '-' || str[n] == '+')
		n++;
	while (n < ft_strlen(str) && str[n] >= '0' && str[n] <= '9')
	{
		i = (i * 10) + (str[n] - '0');
		n++;
	}
	if (str[t] == '-')
		return (i * -1);
	else
		return (i);
}
