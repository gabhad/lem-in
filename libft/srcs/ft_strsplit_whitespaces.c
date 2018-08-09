/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_whitespaces.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:46:18 by ghaddad           #+#    #+#             */
/*   Updated: 2018/08/09 14:46:21 by ghaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordcount(char const *s)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
			i++;
		if (s[i] && s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			word++;
		while (s[i] && s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			i++;
	}
	return (word);
}

static int		ft_lettercount(char const *s)
{
	int i;
	int letter;

	i = 0;
	letter = 0;
	while (s[i] && s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
		i++;
	return (i);
}

char			**ft_strsplit_whitespaces(char const *s)
{
	int		i;
	int		j;
	int		k;
	int		count;
	char	**tab;

	i = 0;
	j = 0;
	k = ft_wordcount(s);
	if ((tab = (char **)malloc(sizeof(char*) * (k + 1))) == NULL)
		return (NULL);
	while (s[i] && j < ft_wordcount(s))
	{
		k = 0;
		while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
			i++;
		count = ft_lettercount(&s[i]);
		tab[j] = ft_strnew(count);
		while (s[i] != ' ' && s[i] != '\t' && s[i] != '\n'
			&& s[i] && (k < count))
			tab[j][k++] = s[i++];
		tab[j++][k] = 0;
	}
	tab[j] = 0;
	return (tab);
}
