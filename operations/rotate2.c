/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 01:23:26 by robinpham         #+#    #+#             */
/*   Updated: 2026/05/21 01:33:30 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate2(t_stack *s)
{
	int	i;
	int	temp;

	i = 0;
	temp = s->data[0];
	while (i < s->size - 1)
	{
		s->data[i] = s->data[i + 1];
		i++;
	}
	s->data[s->size - 1] = temp;
}

void	rra(t_stack *a)
{
	if (is_empty(a) || a->size < 2)
		return ;
	rotate2(a);
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	if (is_empty(b) || b->size < 2)
		return ;
	rotate2 (b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	if (!(is_empty(a) || a->size < 2))
		rotate2(a);
	if (!(is_empty(b) || b->size < 2))
		rotate2 (b);
	ft_printf("rrr\n");
}
