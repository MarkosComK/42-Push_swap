/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:36:11 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/22 18:28:48 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, int move)
{
	t_stack	*tmp;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	*stack = stack_first(*stack);
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	*stack = tmp;
	if (move == SA)
		write(1, "sa\n", 3);
	if (move == SB)
		write(1, "sb\n", 3);
}

void	swap_swap(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
	write(1, "ss\n", 3);
}
