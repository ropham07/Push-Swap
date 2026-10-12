/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opp2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 01:04:19 by robinpham         #+#    #+#             */
/*   Updated: 2026/05/21 01:20:50 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *s)
{
	int	i;
	int	temp;

	i = s->size - 1;
	temp = s->data[i];
	while (i > 0)
	{
		s->data[i] = s->data[i - 1];
		i--;
	}
	s->data[0] = temp;
}

void	ra(t_stack *a)
{
	if (is_empty(a) || a->size < 2)
		return ;
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	if (is_empty(b) || b->size < 2)
		return ;
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	if (!is_empty(a) && a->size >= 2)
		rotate(a);
	if (!is_empty(b) && b->size >= 2)
		rotate(b);
	ft_printf("rr\n");
}
