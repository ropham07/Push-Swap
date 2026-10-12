/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 21:02:43 by robinpham         #+#    #+#             */
/*   Updated: 2026/05/02 22:04:31 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	size_t				i;

	str = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

/*
int main()
{
	const char *str = "Hello, World!";
	char c = 'o';
	size_t n = 13;

	char *result = ft_memchr(str, c, n);
	if (result)
		printf("Character '%c' found at index: %ld\n", c, result - str);
	else
		printf("Character '%c' not found in the string.\n", c);
	return 0;
}
*/