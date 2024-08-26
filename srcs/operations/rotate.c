/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:10:43 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/22 18:26:43 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack, int move)
{
	t_stack	*tmp;

	if (!*stack || !((*stack)->next))
		return ;
	tmp = *stack;
	*stack = stack_last(*stack);
	(*stack)->next = tmp;
	*stack = tmp->next;
	tmp->next = NULL;
	if (move == RA)
		write(1, "ra\n", 3);
	if (move == RB)
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_stack **stack, int move)
{
	t_stack	*tmp;
	int		i;

	if (!*stack || !(*stack)->next)
		return ;
	i = 0;
	tmp = *stack;
	while ((*stack)->next)
	{
		*stack = (*stack)->next;
		i++;
	}
	(*stack)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (move == RRA)
		write(1, "rra\n", 4);
	if (move == RRB)
		write(1, "rra\n", 4);
}

void	rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!*stack_a || !((*stack_a)->next) || !*stack_b || ((*stack_b)->next))
		return ;
	tmp = *stack_a;
	*stack_a = stack_last(*stack_a);
	(*stack_a)->next = tmp;
	*stack_a = tmp->next;
	tmp = *stack_b;
	*stack_b = stack_last(*stack_b);
	(*stack_b)->next = tmp;
	*stack_b = tmp->next;
	tmp->next = NULL;
	write(1, "rr\n", 3);
}

void	reverse_rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		i;

	if (!*stack_a || !((*stack_b)->next) || !*stack_b || ((*stack_b)->next))
		return ;
	i = 0;
	tmp = *stack_a;
	while ((*stack_a)->next)
	{
		*stack_a = (*stack_a)->next;
		i++;
	}
	(*stack_a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	i = 0;
	tmp = *stack_b;
	while ((*stack_b)->next)
	{
		*stack_b = (*stack_b)->next;
		i++;
	}
	(*stack_b)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	write(1, "rrr\n", 4);
}
