/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 09:49:35 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/01 13:33:23 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

bool	execute(t_stack **stack_a, t_stack **stack_b, char *line)
{
	*stack_a = stack_first(*stack_a);
	*stack_b = stack_first(*stack_b);
	if (ft_strcmp(line, "sa\n") == 0)
		swap(stack_a);
	else if (ft_strcmp(line, "sb\n") == 0)
		swap(stack_b);
	else if (ft_strcmp(line, "ss\n") == 0)
		swap_swap(stack_a, stack_b);
	else if (ft_strcmp(line, "pa\n") == 0)
		push(stack_b, stack_a);
	else if (ft_strcmp(line, "pb\n") == 0)
		push(stack_a, stack_b);
	else if (ft_strcmp(line, "ra\n") == 0)
		rotate(stack_a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rotate(stack_b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rotate_rotate(stack_a, stack_b);
	else if (ft_strcmp(line, "rra\n") == 0)
		reverse_rotate(stack_a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		reverse_rotate(stack_b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		reverse_rotate_rotate(stack_a, stack_b);
	else
		return (true);
	return (false);
}
