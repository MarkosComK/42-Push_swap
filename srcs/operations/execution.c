/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:16:50 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/28 18:30:55 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		return (swap(stack_a, SA));
	else if (ft_strcmp(line, "sb") == 0)
		return (swap(stack_b, SB));
	else if (ft_strcmp(line, "ss") == 0)
		return (swap_swap(stack_a, stack_b));
	else if (ft_strcmp(line, "pa") == 0)
		return (push(stack_b, stack_a, PA));
	else if (ft_strcmp(line, "pb") == 0)
		return (push(stack_a, stack_b, PB));
	else if (ft_strcmp(line, "ra") == 0)
		return (rotate(stack_a, RA));
	else if (ft_strcmp(line, "rb") == 0)
		return (rotate(stack_b, RB));
	else if (ft_strcmp(line, "rr") == 0)
		return (rotate_rotate(stack_a, stack_b));
	else if (ft_strcmp(line, "rra") == 0)
		return (reverse_rotate(stack_a, RRA));
	else if (ft_strcmp(line, "rrb") == 0)
		return (reverse_rotate(stack_b, RRB));
	else if (ft_strcmp(line, "rrr") == 0)
		return (reverse_rotate_rotate(stack_a, stack_b));
}

void	multi_execute(t_stack **stack_a, t_stack **stack_b, char *line, int n)
{
	while (n--)
		execute(stack_a, stack_b, line);
}
