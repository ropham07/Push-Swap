/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:41:04 by robinpham         #+#    #+#             */
/*   Updated: 2026/06/12 18:22:30 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	top(t_stack *s)
{
	return (s->data[s->size - 1]);
}

int	is_empty(t_stack *s)
{
	if (s->size == 0)
		return (1);
	else
		return (0);
}

int	is_sorted(t_stack *a)
{
	int	i;

	if (!a || a->size <= 1)
		return (1);
	i = 0;
	while (i < a->size - 1)
	{
		if (a->data[i] > a->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_int_range(long nb)
{
	if (nb < INT_MIN || nb > INT_MAX)
		return (0);
	return (1);
}

void	indice(t_stack *s)
{
	int	i;
	int	j;
	int	indice;
	int	temp[MAX_SIZE];

	i = 0;
	while (i < s->size)
	{
		temp[i] = s->data[i];
		i++;
	}
	i = 0;
	while (i < s->size)
	{
		indice = 0;
		j = 0;
		while (j < s->size)
		{
			if (temp[j] < temp[i])
				indice++;
			j++;
		}
		s->data[i] = indice;
		i++;
	}
}
