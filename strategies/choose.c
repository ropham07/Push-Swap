/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 16:26:42 by mamenego          #+#    #+#             */
/*   Updated: 2026/06/12 18:19:08 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_stack *a, t_stack *b)
{
	float	disorder;

	disorder = compute_disorder(a);
	if (disorder < 0.2)
		sort_simple(a, b);
	else if (disorder < 0.5)
		sort_medium(a, b);
	else
		sort_complex(a, b);
}

void	sort_dispatcher(t_stack *a, t_stack *b)
{
	if (a->size <= 3)
		sort_three(a);
	else if (a->size <= 4)
		sort_four(a, b);
	else if (a->size <= 5)
		sort_five(a, b);
	else
		adaptive_sort(a, b);
}

void	run_strategy(t_stack *a, t_stack *b, t_strategy strategy)
{
	if (a->size <= 3)
		sort_three(a);
	else if (a->size <= 4)
		sort_four(a, b);
	else if (a->size <= 5)
		sort_five(a, b);
	else if (strategy == STRAT_SIMPLE)
		sort_simple(a, b);
	else if (strategy == STRAT_MEDIUM)
		sort_medium(a, b);
	else if (strategy == STRAT_COMPLEX)
		sort_complex(a, b);
	else
		adaptive_sort(a, b);
}
