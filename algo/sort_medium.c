/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:05:40 by robinpham         #+#    #+#             */
/*   Updated: 2026/06/12 03:07:48 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_size(t_stack *a)
{
	int	size;
	int	sqrt;

	size = a->size;
	sqrt = 0;
	while (sqrt * sqrt < size)
		sqrt++;
	return (sqrt);
}

int	find_max_pos(t_stack *a)
{
	int	i;
	int	max;
	int	pos;

	i = 0;
	pos = 0;
	max = a->data[a->size - 1 - i];
	while (i < a->size)
	{
		if (a->data[a->size - 1 - i] > max)
		{
			max = a->data[a->size - 1 - i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

void	bring_to_top(t_stack *a, int pos)
{
	int	i;

	i = 0;
	if (pos <= a->size / 2)
	{
		while (i != pos)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		while (i != (a->size - pos))
		{
			rra(a);
			i++;
		}
	}
}

void	push_chunk(t_stack *a, t_stack *b, int min, int max)
{
	int	size;

	size = a->size;
	while (size--)
	{
		if (top(a) >= min && top(a) <= max)
			pb(a, b);
		else
			ra(a);
	}
}

void	sort_medium(t_stack *a, t_stack *b)
{
	int	min;
	int	max;
	int	size;

	indice(a);
	min = 0;
	max = chunk_size(a);
	size = max;
	while (!is_empty(a))
	{
		push_chunk(a, b, min, max);
		min = max + 1;
		max += size;
	}
	while (!is_empty(b))
	{
		bring_to_top(b, find_max_pos(b));
		pa(a, b);
		ra(a);
	}
}
