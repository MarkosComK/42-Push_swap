/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:00:56 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/21 19:24:44 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	stack_sort(t_stack *stack)
{
	t_stack	*stack_b;

	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (stack_size(stack) == 2)
		ft_printf("stack_size: %d\n", stack_size(stack));
}
