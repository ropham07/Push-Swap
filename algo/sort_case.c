/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 17:54:59 by robinpham         #+#    #+#             */
/*   Updated: 2026/06/12 18:18:31 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	if (is_sorted(a))
		return ;
	top = a->data[a->size - 1];
	mid = a->data[a->size - 2];
	bot = a->data[a->size - 3];
	if (top < mid && top > bot && mid > bot)
		sa(a);
	else if (top < mid && mid < bot)
	{
		sa(a);
		rra(a);
	}
	else if (top < mid && mid > bot && top < bot)
		ra(a);
	else if (top > mid && mid < bot && top > bot)
	{
		sa(a);
		ra(a);
	}
	else if (top > mid && mid < bot && top < bot)
		rra(a);
}

void	sort_four(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	bring_to_top(a, find_min_pos(a));
	pb(a, b);
	sort_three(a);
	pa(a, b);
	ra(a);
}

void	sort_five(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	bring_to_top(a, find_min_pos(a));
	pb(a, b);
	bring_to_top(a, find_min_pos(a));
	pb(a, b);
	sort_three(a);
	pa(a, b);
	ra(a);
	pa(a, b);
	ra(a);
}
