/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 21:16:10 by robinpham         #+#    #+#             */
/*   Updated: 2026/05/07 05:47:13 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*temp;

	if (count != 0 && size > (size_t)-1 / count)
		return (NULL);
	temp = malloc(count * size);
	if (!temp)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		temp[i] = 0;
		i++;
	}
	return (temp);
}

// int	main(void)
// {
// 	int		*tab;
// 	char	*str;
// 	int		i;

// 	// Test 1 : tableau d'entiers
// 	tab = ft_calloc(5, sizeof(int));
// 	printf("Test 1 - tableau d'entiers :\n");
// 	i = 0;
// 	while (i < 5)
// 	{
// 		printf("tab[%d] = %d\n", i, tab[i]);
// 		i++;
// 	}
// 	free(tab);

// 	// Test 2 : tableau de chars
// 	str = ft_calloc(6, sizeof(char));
// 	printf("\nTest 2 - tableau de chars :\n");
// 	i = 0;
// 	while (i < 6)
// 	{
// 		printf("str[%d] = %d\n", i, str[i]);
// 		i++;
// 	}
// 	free(str);

// 	// Test 3 : count = 0
// 	tab = ft_calloc(0, sizeof(int));
// 	printf("\nTest 3 - count = 0 :\n");
// 	if (tab)
// 		printf("pointeur non NULL\n");
// 	else
// 		printf("pointeur NULL\n");
// 	free(tab);

// 	// Test 4 : size = 0
// 	tab = ft_calloc(5, 0);
// 	printf("\nTest 4 - size = 0 :\n");
// 	if (tab)
// 		printf("pointeur non NULL\n");
// 	else
// 		printf("pointeur NULL\n");
// 	free(tab);

// 	return (0);
// }
