/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 06:19:40 by robinpham         #+#    #+#             */
/*   Updated: 2026/05/04 02:04:17 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *s2)
{
	char	*trimmed;
	int		start;
	int		end;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(s2, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end >= start && ft_strchr(s2, s1[end]))
		end--;
	trimmed = malloc(sizeof(char) * (end - start + 2));
	if (!trimmed)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		trimmed[i] = s1[start];
		i++;
		start++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}

/*
int main(void)
{
	const char *s1 = "xxxxxxxxHello, World!xx";
	const char *s2 = "x";
	char *result = ft_strtrim(s1, s2);

	if (result)
		printf("Résultat après trim : '%s'\n", result);
	else
		printf("Erreur lors du trim.\n");
	return (0);
}
*/