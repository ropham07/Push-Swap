/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:53:37 by robinpham         #+#    #+#             */
/*   Updated: 2026/05/03 19:56:22 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

/*
int	main(void)
{
	char *src = "Hello, c'est Robin !";
	char dest[21];
	size_t size = 21;
	size_t result = ft_strlcpy(dest, src, size);
	printf("String copiée : %s\n", dest);
	printf("Taille de la source string: %zu\n", result);
}
*/