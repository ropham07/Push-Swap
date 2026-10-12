/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:01:04 by robinpham         #+#    #+#             */
/*   Updated: 2026/05/10 21:50:32 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunint(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
		i += ft_putunint(n / 10);
	i += ft_putchar((n % 10) + '0');
	return (i);
}
