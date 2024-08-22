/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:00:56 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/22 16:02:12 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_sort(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;

	if (stack_size(*stack_a) == 2)
		swap(stack_a, SA);
	else
	{
		stack_sort_b(stack_a, &stack_b);
		print_stack(*stack_a);
	}
	stack_free(stack_b);
}

void	stack_sort_b(t_stack **stack_a, t_stack **stack_b)
{
	while (!stack_sorted(*stack_a) && stack_size(*stack_a) > 3)
	{
		if (stack_n_is_min(*stack_a))
			ft_printf("min value is: %i\n", (*stack_a)->nbr);
		push(stack_a, stack_b, PB);
	}
	stack_sort_tree(stack_a);
}

void	stack_sort_tree(t_stack **stack_a)
{
	if (stack_n_is_min(*stack_a))
		ft_printf("min value is: %i\n", (*stack_a)->nbr);
	if (stack_n_is_max(*stack_a))
		ft_printf("max value is: %i\n", (*stack_a)->nbr);
	/*
	while (!stack_sorted(*stack_a))
	{
		if (stack_n_is_min(*stack_a))
			ft_printf("true");
	}
	*/
}
