/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:57:38 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/01 11:44:59 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push(t_stack **stack_1, t_stack **stack_2, int move)
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
	if (move == PA)
		write(1, "pa\n", 3);
	if (move == PB)
		write(1, "pb\n", 3);
}

void	rotate(t_stack **stack, int move)
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
	if (move == RA)
		write(1, "ra\n", 3);
	if (move == RB)
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_stack **stack, int move)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	*stack = stack_last(*stack);
	tmp = stack_first(*stack);
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
	(*stack)->prev = NULL;
	(*stack)->next = tmp;
	tmp->prev = *stack;
	if (move == RRA)
		write(1, "rra\n", 4);
	if (move == RRB)
		write(1, "rrb\n", 4);
}

void	rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a || !((*stack_a)->next) || !*stack_b || !((*stack_b)->next))
		return ;
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	write(1, "rr\n", 3);
}

void	reverse_rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a, 0);
	reverse_rotate(stack_b, 0);
	write(1, "rrr\n", 4);
}
