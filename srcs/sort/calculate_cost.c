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

int	calculate_cost(t_stack **stack_a, t_stack **stack_b)
{
	int	cost;
	int	max_nbr;

	cost = -1;
	max_nbr = stack_max(*stack_b);
	if ((*stack_a)->nbr > max_nbr && max_nbr == (*stack_b)->nbr)
		cost = 1;
	//ft_printf("pushing number: %i\n", (*stack_a)->nbr);
	//ft_printf("biggest value in B: %i\n", stack_max(*stack_b));
	return (cost);
}
