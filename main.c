/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 19:09:27 by mamenego          #+#    #+#             */
/*   Updated: 2026/06/12 18:33:08 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_strategy	strategy;
	int			start;

	a.size = 0;
	b.size = 0;
	if (argc < 2)
		return (0);
	if (!parse_strategy(argc, argv, &strategy))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	start = get_numbers_start(argc, argv);
	if (!parse_args(argc, argv, &a, start))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (is_sorted(&a))
		return (0);
	run_strategy(&a, &b, strategy);
	return (0);
}
