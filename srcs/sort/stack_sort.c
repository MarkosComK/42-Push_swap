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
	else
		sort_all(stack_a, stack_b);
	print_stacks(stack_a, stack_b);
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
	}
	stack_sort_three(stack_a);
	multi_execute(&stack_a, &stack_b, "pa", len - 3);
}

// attr[3]: attr[0] = min, attr[1] = index, attr[2] = len
void	sort_all(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	pos[2];
	int	mode;

	multi_execute(&stack_a, &stack_b, "pb", 2);
	print_stacks(stack_a, stack_b);
	while (stack_size(stack_a) > 3)
	{
		pos[0] = find_min_index(stack_a, stack_b, stack_size(stack_a));
		i = -1;
		while (++i < pos[0])
			stack_a = stack_a->next;
		pos[1] = execute_calc(stack_a, stack_b, stack_size(stack_a), true);
		mode = lcm(pos, stack_size(stack_a), stack_size(stack_b), true);
		if (mode == 1)
		{
			reverse_pos(&stack_a, &stack_b, pos);
		}
		printf("mod: %i\n", mode);
		execute_ps(&stack_a, &stack_b, pos, mode);
	print_stacks(stack_a, stack_b);
		execute(&stack_a, &stack_b, "pb");
	}
	stack_sort_three(stack_a);
	while (stack_size(stack_b) > 0)
	{
		target_push(stack_a, find_target(stack_b, stack_a));
		execute(&stack_a, &stack_b, "pa");
	}
	min_push(stack_a);
}

int	find_target(t_stack *stack_from, t_stack *stack_to)
{
	t_stack	*tmp;
	int		target;

	tmp = stack_first(stack_to);
	target = tmp->nbr;
	if (stack_from->nbr > stack_max(stack_to))
		return (min_pos(stack_to));
	while (tmp)
	{
		if ((tmp->nbr < target && tmp->nbr > stack_from->nbr)
			|| (tmp->nbr > stack_from->nbr
				&& target < stack_from->nbr))
			target = tmp->nbr;
		tmp = tmp->next;
	}
	return (node_index(stack_to, target));
}

void	execute_ps(t_stack **stack_a, t_stack **stack_b, int pos[2], int mode)
{
	if (mode == 0 || mode == 1)
		exec_smt(stack_a, stack_b, pos, mode);
	else if (mode == 2)
	{
		multi_execute(stack_a, stack_b, "ra", pos[0]);
		multi_execute(stack_a, stack_b, "rrb", stack_size(*stack_b) - pos[1]);
	}
	else if (mode == 3)
	{
		multi_execute(stack_a, stack_b, "rra", stack_size(*stack_a) - pos[0]);
		multi_execute(stack_a, stack_b, "rb", pos[1]);
	}
}

void	exec_smt(t_stack **stack_a, t_stack **stack_b, int pos[2], int mode)
{
	if (mode == 0)
	{
		multi_execute(stack_a, stack_b, "rr", min(pos[0], pos[1]));
		if (max(pos[0], pos[1]) == pos[0] && pos[0] != pos[1])
			multi_execute(stack_a, stack_a, "ra", pos[0] - pos[1]);
		else if (max(pos[0], pos[1]) == pos[1] && pos[0] != pos[1])
			multi_execute(stack_a, stack_b, "rb", pos[1] - pos[0]);
	}
	else if (mode == 1)
	{
		multi_execute(stack_a, stack_b, "rrr", min(pos[0], pos[1]));
		if (max(pos[0], pos[1]) == pos[0] && pos[0] != pos[1])
			multi_execute(stack_a, stack_a, "rra", pos[0] - pos[1]);
		else if (max(pos[0], pos[1]) == pos[1] && pos[0] != pos[1]
			&& pos[1] != 0)
			multi_execute(stack_a, stack_b, "rrb", pos[1] - pos[0]);
	}
}
void	reverse_pos(t_stack **stack_a, t_stack **stack_b, int pos[2])
{
	pos[0] = stack_size(*stack_a) - pos[0];
	if (pos[1] != 0)
		pos[1] = stack_size(*stack_b) - pos[1];
}

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
}
