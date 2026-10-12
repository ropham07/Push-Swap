/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 21:10:49 by robinpham         #+#    #+#             */
/*   Updated: 2026/05/02 22:04:27 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*a;
	const unsigned char	*b;
	size_t				i;

	a = (const unsigned char *)s1;
	b = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (0);
}

/*
int main()
{
	const char *str1 = "Hello, World!";
	const char *str2 = "Hello, World!";
	size_t n = 13;

	int result = ft_memcmp(str1, str2, n);
	if (result == 0)
		printf("The memory blocks are equal.\n");
	else if (result < 0)
		printf("The first memory block is less than the second.\n");
	else
		printf("The first memory block is greater than the second.\n");
	return 0;
}
*/