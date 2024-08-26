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
	while (stack_size(*stack_a) > 0)
	{
		if (calculate_cost(stack_a, stack_b) == -1)
		{
			ft_printf("operation is PB\n");
			push(stack_a, stack_b, PB);
		}
		else if (calculate_cost(stack_a, stack_b) == 1 && index_of((*stack_a)->nbr , *stack_a) == 1)
		{
			ft_printf("operation is PB\n");
			push(stack_a, stack_b, PB);
		}
		else if (calculate_cost(stack_a, stack_b) == 2 &&
		(*stack_a)->nbr < stack_min(*stack_b) && stack_min(*stack_b) == 
		stack_last(*stack_b)->nbr)
		{
			ft_printf("operations is PB + RB\n");
			push(stack_a, stack_b, PB);
			rotate(stack_b, RB);
		}
		else if (calculate_cost(stack_a, stack_b) == 2 &&
		index_of(get_number_below((*stack_a)->nbr, *stack_b), *stack_b) == 2)
		{
			ft_printf("operation is PB + SB\n");
			push(stack_a, stack_b, PB);
			swap(stack_b, SB);
		}
		else if (calculate_cost(stack_a, stack_b) == 4 &&
		index_of(get_number_below((*stack_a)->nbr, *stack_b), *stack_b) == 3)
		{
			ft_printf("operation is RB + RB");
			rotate(stack_b, RB);
			push(stack_a, stack_b, PB);
			rotate(stack_b, RB);
			reverse_rotate(stack_b, RRB);
		}
		else if (calculate_cost(stack_a, stack_b) == 7 &&
			index_of(get_number_below((*stack_a)->nbr, *stack_b), *stack_b) ==
		index_of(stack_last(*stack_b)->nbr, *stack_b) - 1)
		{
			ft_printf("operation is RRB + RRB + PB + SB + RB + RB + RB\n");
			reverse_rotate(stack_b, RRB);
			reverse_rotate(stack_b, RRB);
			push(stack_a, stack_b, PB);
			rotate(stack_b, RB);
			rotate(stack_b, RB);
			rotate(stack_b, RB);
		}
		else
			push(stack_a, stack_b, PB);
		print_stacks(*stack_a, *stack_b);
	}
	print_stacks(*stack_a, *stack_b);
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
