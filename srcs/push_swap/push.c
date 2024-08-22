/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:53:33 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/22 13:16:06 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_1, t_stack **stack_2, int move)
{
	t_stack	*tmp;

	if (!*stack_1)
		return ;
	tmp = *stack_2;
	*stack_2 = *stack_1;
	*stack_1 = (*stack_1)->next;
	(*stack_2)->next = tmp;
	if (move == PA)
		write(1, "pa\n", 3);
	if (move == PB)
		write(1, "pb\n", 3);
}
