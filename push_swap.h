/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 00:21:26 by robinpham         #+#    #+#             */
/*   Updated: 2026/06/12 18:03:14 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

# define MAX_SIZE 500

/*
** Structures & Enums
*/

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strategy;

typedef struct s_stack
{
	int	data[MAX_SIZE];
	int	size;
}	t_stack;

/*
** Parsing & Validation
*/

int		is_strategy_flag(char *str);
int		parse_strategy(int argc, char **argv, t_strategy *strategy);
int		get_numbers_start(int argc, char **argv);
int		parse_args(int argc, char **argv, t_stack *a, int start);
int		is_number(char *str);
int		is_int_range(long nb);
int		has_duplicate(t_stack *a, int value);
long	ft_atol(char *str);
int		push_back_stack(t_stack *a, int value);

/*
** Stack Utils
*/

int		top(t_stack *s);
int		is_empty(t_stack *s);
int		is_sorted(t_stack *a);
void	indice(t_stack *s);
double	compute_disorder(t_stack *a);
void	bring_to_top(t_stack *a, int pos);
int		find_min_pos(t_stack *a);

/*
** Stack Operations
*/

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/*
** Sorting Algorithms
*/

void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	sort_simple(t_stack *a, t_stack *b);
void	sort_simple(t_stack *a, t_stack *b);
void	sort_medium(t_stack *a, t_stack *b);
void	sort_complex(t_stack *a, t_stack *b);

/*
** Strategy & Dispatch
*/

void	run_strategy(t_stack *a, t_stack *b, t_strategy strategy);
void	adaptive_sort(t_stack *a, t_stack *b);
void	sort_dispatcher(t_stack *a, t_stack *b);
void	choose_and_run_strategy(t_stack *a, t_stack *b);

#endif