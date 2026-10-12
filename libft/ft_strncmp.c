/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 19:02:37 by robinpham         #+#    #+#             */
/*   Updated: 2026/05/04 02:19:49 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < (n - 1) && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
int main(void)
{
	printf("%d\n", ft_strncmp("abc", "abc", 3));   // 0
	printf("%d\n", ft_strncmp("abc", "abd", 3));   // négatif
	printf("%d\n", ft_strncmp("abd", "abc", 3));   // positif
	printf("%d\n", ft_strncmp("abc", "abc", 0));   // 0
	printf("%d\n", ft_strncmp("abc", "abcd", 3));  // 0
}
*/
