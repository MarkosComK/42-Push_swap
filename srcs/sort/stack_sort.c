/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:00:56 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/26 14:09:54 by marsoare         ###   ########.fr       */
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
	}
	stack_free(stack_b);
}

void	stack_sort_b(t_stack **stack_a, t_stack **stack_b)
{
	while (!stack_sorted(*stack_a) && stack_size(*stack_a) > 3)
	{
		ft_printf("cost of number: %i is %i\n", (*stack_a)->nbr, calculate_cost(stack_a, stack_b));
		ft_printf("the number below %i is %i\n",
			(*stack_a)->nbr, get_number_below((*stack_a)->nbr, *stack_b));
		print_stacks(*stack_a, *stack_b);
		push(stack_a, stack_b, PB);
	}
	if (stack_size(*stack_b) > 0)
		stack_sort_ten(stack_a, stack_b);
	//print_stack(*stack_a);
	//print_stack(*stack_b);
	//stack_sort_tree(stack_a);
}

void	stack_sort_ten(t_stack **stack_a, t_stack **stack_b)
{
	//stack_sort_tree(stack_a);
	(void) stack_b;
	while(stack_size(*stack_a) > 3)
	{
		ft_printf("pushing number: %i - \n", (*stack_a)->nbr);
	}
}

void	stack_sort_tree(t_stack **stack_a)
{
	while (!stack_sorted(*stack_a))
	{
		if (stack_n_is_min(*stack_a))
		{
			swap(stack_a, SA);
			rotate(stack_a, RA);
		}
		else if (stack_n_is_max(*stack_a))
		{
			rotate(stack_a, RA);
			if (!stack_sorted(*stack_a))
				swap(stack_a, SA);
		}
		else if ((*stack_a)->nbr > (*stack_a)->next->nbr)
			swap(stack_a, SA);
		else if ((*stack_a)->nbr < (*stack_a)->next->nbr)
			reverse_rotate(stack_a, RRA);
	}
}
