/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 14:10:53 by robinpham         #+#    #+#             */
/*   Updated: 2026/06/12 02:59:59 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack *s)
{
	int	max;
	int	i;

	i = 1;
	max = s->data[0];
	while (i < s->size)
	{
		if (s->data[i] > max)
			max = s->data[i];
		i++;
	}
	return (max);
}

int	get_bit_count(int max)
{
	int	count;

	count = 0;
	while (max > 0)
	{
		max /= 2;
		count++;
	}
	return (count);
}

int	get_bit(int n, int bit)
{
	while (bit > 0)
	{
		n /= 2;
		bit--;
	}
	return (n % 2);
}

void	sort_complex(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	bit_count;
	int	size;

	indice(a);
	bit_count = get_bit_count(get_max(a));
	size = a->size;
	i = 0;
	while (i < bit_count)
	{
		j = 0;
		while (j < size)
		{
			if (get_bit(top(a), i) == 1)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (!is_empty(b))
			pa(a, b);
		i++;
	}
}
