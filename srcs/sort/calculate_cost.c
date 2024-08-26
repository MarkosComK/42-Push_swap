/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:14:06 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/26 13:52:05 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_cost(t_stack *stack_a, t_stack **stack_b)
{
	int	cost;
	int	max_nbr;
	int	min_nbr;

	if (!stack_a || !*stack_b)
		return (-1);
	cost = -1;
	max_nbr = stack_max(*stack_b);
	min_nbr = stack_min(*stack_b);
	if ((stack_a)->nbr > max_nbr && max_nbr == (*stack_b)->nbr)
		cost = 1; // PB
	else if ((stack_a)->nbr < min_nbr && min_nbr == stack_last(*stack_b)->nbr)
		cost = 2; // PB + RB
	else if (index_of(get_number_below((stack_a)->nbr, *stack_b), *stack_b) == 1
		&& stack_size(*stack_b) < 3)
		cost = 2; // RB + PB
	else if (index_of(get_number_below((stack_a)->nbr, *stack_b), *stack_b) == 1
		&& stack_size(*stack_b) >= 3)
		cost = 2; // PB + SB
	else if (index_of(get_number_below((stack_a)->nbr, *stack_b), *stack_b) == 
		index_of(stack_last(*stack_b)->nbr, *stack_b))
		cost = 4; // RRB + PB + RB + RB;
	else if (index_of(get_number_below((stack_a)->nbr, *stack_b), *stack_b) == 2)
		cost = 5; // RB + PB + RB + RRB + RRB;
	else if (index_of(get_number_below((stack_a)->nbr, *stack_b), *stack_b) ==
		index_of(stack_last(*stack_b)->nbr, *stack_b) - 1)
		cost = 7; // RRB + RRB + PB + SB + RB + RB + RB;
	return (cost);
}

int	get_number_below(int number, t_stack *stack)
{
	int	below;

	below = -1;
	while (stack)
	{
		if (number > stack->nbr && stack->nbr > below)
			below = stack->nbr;
		stack = stack->next;
	}
	return (below);
}

int	index_of(int number, t_stack *stack)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (number == stack->nbr)
			return (index);
		stack = stack->next;
		index++;
	}
	return (index);
}

int	find_lowest_cost_move(t_stack **stack_a, t_stack **stack_b)
{
    int	cost = 999; // Initialize cost to a high value
    int	best_index = -1;
    int	i;
    t_stack *tmp = *stack_a;

    for (i = 0; i < 3; i++) {
        int current_cost = calculate_cost(tmp, stack_b) + i;
        if (current_cost != -1 && current_cost < cost) {
            cost = current_cost;
            best_index = cost;
			ft_printf("number is %i\n", tmp->nbr);
        }
        tmp = tmp->next;
    }
    return best_index;
}
