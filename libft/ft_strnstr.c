/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 19:32:33 by robinpham         #+#    #+#             */
/*   Updated: 2026/05/02 22:03:55 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] && (i + j) < len)
			j++;
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

/*
int main()
{
	const char *haystack = "Hello, World!";
	const char *needle = "World";
	size_t len = 12;

	char *result = ft_strnstr(haystack, needle, len);
	if (result)
		printf("Substring found: %s\n", result);
	else
		printf("Substring not found within the specified length.\n");
	return 0;
}
*/