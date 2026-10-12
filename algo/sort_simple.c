/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 19:53:15 by robinpham         #+#    #+#             */
/*   Updated: 2026/06/12 18:26:02 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_stack *stack)
{
	int	i;
	int	min;
	int	pos;

	if (!stack || stack->size == 0)
		return (-1);
	i = 0;
	pos = 0;
	min = stack->data[stack->size - 1];
	while (i < stack->size)
	{
		if (stack->data[stack->size - 1 - i] < min)
		{
			min = stack->data[stack->size - 1 - i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

void	bring_to_top_a(t_stack *a, int pos)
{
	if (pos <= a->size / 2)
	{
		while (pos > 0)
		{
			ra(a);
			pos--;
		}
	}
	else
	{
		pos = a->size - pos;
		while (pos > 0)
		{
			rra(a);
			pos--;
		}
	}
}

void	bring_to_top_b(t_stack *b, int pos)
{
	if (pos <= b->size / 2)
	{
		while (pos > 0)
		{
			rb(b);
			pos--;
		}
	}
	else
	{
		pos = b->size - pos;
		while (pos > 0)
		{
			rrb(b);
			pos--;
		}
	}
}

void	sort_simple(t_stack *a, t_stack *b)
{
	while (!is_empty(a))
	{
		bring_to_top_a(a, find_min_pos(a));
		pb(a, b);
	}
	while (!is_empty(b))
	{
		bring_to_top_b(b, find_min_pos(b));
		pa(a, b);
	}
}
