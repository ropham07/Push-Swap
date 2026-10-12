/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:26:43 by robinpham         #+#    #+#             */
/*   Updated: 2026/05/02 22:03:42 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long n)
{
	int	len;

	len = (n <= 0);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	long	n;
	char	*str;
	int		len;

	n = nbr;
	len = ft_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		n = -n;
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	if (nbr < 0)
		str[0] = '-';
	return (str);
}

/*
int main(void)
{
	int number = -12345;
	char *str = ft_itoa(number);
	if (str)
	{
		printf("Le nombre %d converti en chaîne de caractères est : 
		%s\n", number, str);
		free(str);
	}
	else
	{
		printf("Erreur d'allocation mémoire.\n");
	}
	return (0);
}
*/