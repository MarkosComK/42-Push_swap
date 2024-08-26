/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:45:46 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/26 14:06:37 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_min(t_stack *stack)
{
	int	value;

	value = stack->nbr;
	while (stack)
	{
		if (value > stack->nbr)
			value = stack->nbr;
		stack = stack->next;
	}
	return (value);
}

int	stack_max(t_stack *stack)
{
	int	value;

	value = stack->nbr;
	while (stack)
	{
		if (value < stack->nbr)
			value = stack->nbr;
		stack = stack->next;
	}
	return (value);
}

int	stack_n_is_min(t_stack *stack)
{
	int		size;
	t_stack	*tmp;

	size = stack_size(stack);
	tmp = stack;
	while (size > 1)
	{
		if (tmp->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
		size -= 1;
	}
	return (1);
}

int	stack_n_is_max(t_stack *stack)
{
	int		size;
	t_stack	*tmp;

	size = stack_size(stack);
	tmp = stack;
	while (size > 1)
	{
		if (tmp->nbr < stack->next->nbr)
			return (0);
		stack = stack->next;
		size -= 1;
	}
	return (1);
}
