/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:00:56 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/28 20:18:30 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_sort(t_stack *stack_a, t_stack *stack_b)
{
	stack_a = stack_first(stack_a);
	if (stack_sorted(stack_a))
		return ;
	if (stack_size(stack_a) == 2)
		execute(&stack_a, &stack_b, "sa");
	else if (stack_size(stack_a) == 3)
		stack_sort_three(stack_a);
	else if (stack_size(stack_a) > 3 && stack_size(stack_a) < 6)
		sort_five(stack_a, stack_b, stack_size(stack_a));
	//else
		//sort(stack_a, stack_b);
}

// push 2 smallest number to stack b, sort 3 stack a, push back to stack a
void	sort_five(t_stack *stack_a, t_stack *stack_b, int len)
{
	int	tmp;

	tmp = len;
	while (tmp-- > 3)
	{
		min_push(stack_a);
		execute(&stack_a, &stack_b, "pb");
		print_stacks(stack_a, stack_b);
	}
	stack_sort_three(stack_a);
	multi_execute(&stack_a, &stack_b, "pa", len - 3);
}
/*
// attr[3]: attr[0] = min, attr[1] = index, attr[2] = len
void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	pos[2];
	int	mode;

	multi_execute(&stack_a, &stack_b, "pb", 2);
	while (stack_len(stack_a) > 3)
	{
		pos[0] = find_min_index(stack_a, stack_b, stack_len(stack_a));
		i = -1;
		while (++i < pos[0])
			stack_a = stack_a->next;
		pos[1] = execute_calc(stack_a, stack_b, stack_len(stack_a), true);
		mode = lcm(pos, stack_len(stack_a), stack_len(stack_b), true);
		if (mode == 1)
			reverse_pos(&stack_a, &stack_b, pos);
		execute_ps(&stack_a, &stack_b, pos, mode);
		execute(&stack_a, &stack_b, "pb", false);
	}
	sort_three(stack_a);
	while (stack_len(stack_b) > 0)
	{
		target_push(stack_a, find_target(stack_b, stack_a));
		execute(&stack_a, &stack_b, "pa", false);
	}
	min_max_push(stack_a, false);
}
*/

void	stack_sort_three(t_stack *stack_a)
{
	while (!stack_sorted(stack_a))
	{
		if (stack_n_is_min(stack_a))
		{
			execute(&stack_a, NULL, "sa");
			execute(&stack_a, NULL, "ra");
		}
		else if (stack_n_is_max(stack_a))
		{
			execute(&stack_a, NULL, "ra");
			if (!stack_sorted(stack_a))
				execute(&stack_a, NULL, "sa");
		}
		else if (stack_a->nbr > stack_a->next->nbr)
			execute(&stack_a, NULL, "sa");
		else if (stack_a->nbr < stack_a->next->nbr)
			execute(&stack_a, NULL, "rra");
	}
	print_stack(stack_a);
}
