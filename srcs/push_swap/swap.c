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

	if (!*stack || !((*stack)->next))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	if (move == SA)
		write(1, "sa\n", 3);
	if (move == SB)
		write(1, "sb\n", 3);
}

void	swap_swap(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	if (!*stack_a || !((*stack_a)->next) || !*stack_b || !((*stack_b)->next))
		return ;
	tmp_a = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp_a->next = (*stack_a)->next;
	(*stack_a)->next = tmp_a;
	tmp_b = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp_b->next = (*stack_b)->next;
	(*stack_b)->next = tmp_b;
	write(1, "ss\n", 3);
}
