/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 00:28:40 by robinpham         #+#    #+#             */
/*   Updated: 2026/06/11 20:10:17 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	if (is_empty(b))
		return ;
	a->data[a->size] = b->data[b->size - 1];
	b->size -= 1;
	a->size += 1;
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (is_empty(a))
		return ;
	b->data[b->size] = a->data[a->size - 1];
	a->size -= 1;
	b->size += 1;
	ft_printf("pb\n");
}

void	sa(t_stack *a)
{
	int	temp;

	if (a->size < 2)
		return ;
	temp = a->data[a->size - 1];
	a->data[a->size - 1] = a->data[a->size - 2];
	a->data[a->size - 2] = temp;
	ft_printf ("sa\n");
}

void	sb(t_stack *b)
{
	int	temp;

	if (b->size < 2)
		return ;
	temp = b->data[b->size - 1];
	b->data[b->size - 1] = b->data[b->size - 2];
	b->data[b->size - 2] = temp;
	ft_printf ("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	int	temp;

	if (a->size >= 2)
	{
		temp = a->data[a->size - 1];
		a->data[a->size - 1] = a->data[a->size - 2];
		a->data[a->size - 2] = temp;
	}
	if (b->size >= 2)
	{
		temp = b->data[b->size - 1];
		b->data[b->size - 1] = b->data[b->size - 2];
		b->data[b->size - 2] = temp;
	}
	ft_printf("ss\n");
}
