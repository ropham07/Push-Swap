/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 19:03:53 by robinpham         #+#    #+#             */
/*   Updated: 2026/05/02 22:04:20 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;

	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (dest < source)
		while (len--)
			*dest++ = *source++;
	else
	{
		dest += len;
		source += len;
		while (len--)
			*--dest = *--source;
	}
	return (dst);
}

/*
int main()
{
	char str[] = "Hello, World!";
	ft_memmove(str + 7, str, 5);
	printf("Result: %s\n", str);
	return 0;
}
*/