/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:35:00 by robinpham         #+#    #+#             */
/*   Updated: 2026/05/10 21:50:19 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (ft_putstr("(nil)"));
	i += ft_putstr("0x");
	i += ft_puthex_long(n, 0);
	return (i);
}
