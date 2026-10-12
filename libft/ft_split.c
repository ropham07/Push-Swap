/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 05:02:12 by robinpham         #+#    #+#             */
/*   Updated: 2026/05/07 05:08:55 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(const char *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == sep)
			i++;
		else
		{
			while (str[i] && str[i] != sep)
				i++;
			count++;
		}
	}
	return (count);
}

static int	ft_word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	ft_free_tab(char **tab, int j)
{
	while (j > 0)
		free(tab[--j]);
	free(tab);
}

char	**ft_split(const char *s, const char c)
{
	int		i;
	int		j;
	int		len;
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!tab)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i])
	{
		if (s[i] != c)
		{
			len = ft_word_len(s + i, c);
			tab[j] = ft_substr(s, i, len);
			if (!tab[j++])
				return (ft_free_tab(tab, j - 1), NULL);
			i += len - 1;
		}
	}
	tab[j] = NULL;
	return (tab);
}
