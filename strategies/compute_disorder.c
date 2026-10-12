/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 16:16:37 by mamenego          #+#    #+#             */
/*   Updated: 2026/06/12 18:26:49 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_loops(int *arr, int size, int *mistakes, int *total_pairs)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			(*total_pairs)++;
			if (arr[i] > arr[j])
				(*mistakes)++;
			j++;
		}
		i++;
	}
}

double	compute_disorder(t_stack *a)
{
	int		size;
	int		mistakes;
	int		total_pairs;
	int		*arr;

	arr = a->data;
	size = a->size;
	mistakes = 0;
	total_pairs = 0;
	process_loops(arr, size, &mistakes, &total_pairs);
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}
