/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 21:33:39 by robinpham         #+#    #+#             */
/*   Updated: 2026/05/10 21:49:15 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putunint(unsigned int n);
int	ft_puthex(unsigned int n, int upp);
int	ft_puthex_long(unsigned long n, int upp);
int	ft_putptr(unsigned long n);
int	ft_dispatcher(char str, va_list *args);
int	ft_printf(const char *str, ...);

#endif
