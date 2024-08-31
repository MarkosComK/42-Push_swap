/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:18:04 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/31 10:26:48 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
