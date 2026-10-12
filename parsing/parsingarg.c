/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingarg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamenego <mamenego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:41:40 by mamenego          #+#    #+#             */
/*   Updated: 2026/06/11 18:55:58 by mamenego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//on verifie lentree

int	is_number(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicate(t_stack *a, int value)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->data[i] == value)
			return (1);
		i++;
	}
	return (0);
}

int	push_back_stack(t_stack *s, int value)
{
	if (s->size >= MAX_SIZE)
		return (0);
	s->data[s->size] = value;
	s->size++;
	return (1);
}

long	ft_atol(char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	parse_args(int argc, char **argv, t_stack *a, int start)
{
	int		i;
	long	value;

	i = start;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (0);
		value = ft_atol(argv[i]);
		if (value < INT_MIN || value > INT_MAX)
			return (0);
		if (has_duplicate(a, (int)value))
			return (0);
		if (!push_back_stack(a, (int)value))
			return (0);
		i++;
	}
	return (1);
}
