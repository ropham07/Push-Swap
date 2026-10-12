/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamenego <mamenego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:02:43 by mamenego          #+#    #+#             */
/*   Updated: 2026/06/11 18:00:44 by mamenego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_strategy_flag(char *str)
{
	if (!str)
		return (0);
	if (!ft_strcmp(str, "--simple"))
		return (1);
	if (!ft_strcmp(str, "--medium"))
		return (1);
	if (!ft_strcmp(str, "--complex"))
		return (1);
	if (!ft_strcmp(str, "--adaptive"))
		return (1);
	return (0);
}

int	parse_strategy(int argc, char **argv, t_strategy *strategy)
{
	*strategy = STRAT_ADAPTIVE;
	if (argc < 2)
		return (1);
	if (!ft_strcmp(argv[1], "--simple"))
		*strategy = STRAT_SIMPLE;
	else if (!ft_strcmp(argv[1], "--medium"))
		*strategy = STRAT_MEDIUM;
	else if (!ft_strcmp(argv[1], "--complex"))
		*strategy = STRAT_COMPLEX;
	else if (!ft_strcmp(argv[1], "--adaptive"))
		*strategy = STRAT_ADAPTIVE;
	else if (argv[1][0] == '-' && argv[1][1] == '-')
		return (0);
	return (1);
}

int	get_numbers_start(int argc, char **argv)
{
	if (argc > 1 && is_strategy_flag(argv[1]))
		return (2);
	return (1);
}
