/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:00:56 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/22 13:11:42 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	stack_sort(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;

	if (stack_size(*stack_a) == 2)
		swap(stack_a, SA);
	else
	{
		push(stack_a, &stack_b, PB);
		push(stack_a, &stack_b, PB);
		swap(&stack_b, SB);
		print_stack(stack_b);
	}
	stack_free(stack_b);
}
