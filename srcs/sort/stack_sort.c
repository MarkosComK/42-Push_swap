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
		stack_sort_three(&stack_a);
	else if (stack_size(stack_a) > 3 && stack_size(stack_a) < 6)
		sort_tri_adv(stack_a, stack_b, len);
	else
		sort(stack_a, stack_b);
}

// push 2 smallest number to stack b, sort 3 stack a, push back to stack a
void	sort_tri_adv(t_node *stack_a, t_node *stack_b, int len)
{
	int	tmp;

	tmp = len;
	while (tmp-- > 3)
	{
		min_push(stack_a);
		execute(&stack_a, &stack_b, "pb", false);
	}
	sort_three(stack_a);
	multi_execute(&stack_a, &stack_b, "pa", len - 3);
}

// attr[3]: attr[0] = min, attr[1] = index, attr[2] = len
void	sort(t_node *stack_a, t_node *stack_b)
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

void	stack_sort_b(t_stack **stack_a, t_stack **stack_b)
{
	while (stack_size(*stack_a) > 3 && stack_size(*stack_b) < 2)
	{
		push(stack_a, stack_b, PB);
		print_stacks(*stack_a, *stack_b);
	}
	while (stack_size(*stack_a) > 3)
		stack_sort_ten(stack_a, stack_b);
	if (!stack_sorted(*stack_a))
		stack_sort_tree(stack_a);
	int j = 0;
	while (stack_size(*stack_b) > 3 && j < 0)
	{
		stack_sort_ten(stack_b, stack_a);
		j++;
	}
	print_stacks(*stack_a, *stack_b);
}

void	stack_sort_ten(t_stack **stack_a, t_stack **stack_b)
{
	t_cost_index	*cost_index = NULL;
	int	i = 0;
	while (stack_size(*stack_a) > 3 && i < 5)
	{
		cost_index = find_lowest_cost_move(stack_a, stack_b);
		ft_printf("cost: %i index: %i\n", cost_index->cost, cost_index->index);
		if (cost_index->cost == 1 && index_of((*stack_a)->nbr, *stack_a) == 0)
			push(stack_a, stack_b, PB);
		else if (cost_index->cost == 2 && (*stack_a)->nbr < stack_min(*stack_b) &&
			stack_min(*stack_b) == stack_last(*stack_b)->nbr)
		{
			push(stack_a, stack_b, PB);
			rotate(stack_b, RB);
		}
		else if (cost_index->cost == 2 && index_of(get_number_below(
			(*stack_a)->nbr, *stack_b), *stack_b) == 1 && stack_size(*stack_b) < 3)
		{
			rotate(stack_b, RB);
			push(stack_a, stack_b, PB);
		}
		else if (cost_index->cost == 2 && index_of(get_number_below(
			(*stack_a)->nbr, *stack_b), *stack_b) == 1 && stack_size(*stack_b) >= 3)
		{
			push(stack_a, stack_b, PB);
			swap(stack_b, SB);
		}
		else if (cost_index->cost == 2 && cost_index->index == 1)
		{
			ft_printf("this is the case\n");
			swap(stack_a, SA);
			push(stack_a, stack_b, PB);
		}
		print_stacks(*stack_a, *stack_b);
		cost_index->cost = -1;
		i++;
	}
}

void	stack_sort_three(t_stack **stack_a)
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
