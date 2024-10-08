/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:53:33 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/31 10:38:13 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
