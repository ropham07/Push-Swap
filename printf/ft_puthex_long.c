/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 22:04:16 by robinpham         #+#    #+#             */
/*   Updated: 2026/05/10 21:50:07 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_long(unsigned long n, int upp)
{
	char	*hexa;
	int		i;

	i = 0;
	if (upp == 1)
		hexa = "0123456789ABCDEF";
	else
		hexa = "0123456789abcdef";
	if (n > 15)
		i += ft_puthex_long(n / 16, upp);
	i += ft_putchar(hexa[n % 16]);
	return (i);
}
