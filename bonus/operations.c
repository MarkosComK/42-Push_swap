/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:57:38 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/01 13:33:41 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*tmp;

	if (!*stack_1 || !stack_1)
		return ;
	*stack_1 = stack_first(*stack_1);
	*stack_2 = stack_first(*stack_2);
	tmp = (*stack_1)->next;
	if (tmp != NULL)
		tmp->prev = NULL;
	(*stack_1)->next = *stack_2;
	if (*stack_2)
		(*stack_2)->prev = *stack_1;
	*stack_2 = *stack_1;
	*stack_1 = tmp;
}

void	rotate(t_stack **stack)
{
	t_stack	*first;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	*stack = stack_first(*stack);
	first = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	first->prev = stack_last(*stack);
	stack_last(*stack)->next = first;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	*stack = stack_last(*stack);
	tmp = stack_first(*stack);
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
	(*stack)->prev = NULL;
	(*stack)->next = tmp;
	tmp->prev = *stack;
}

void	rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a || !((*stack_a)->next) || !*stack_b || !((*stack_b)->next))
		return ;
	rotate(stack_a);
	rotate(stack_b);
}

void	reverse_rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a || !((*stack_a)->next) || !*stack_b || !((*stack_b)->next))
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
