/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:37:33 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/22 16:00:36 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	stack_check_dup(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->nbr == tmp->nbr)
				return (1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}

int	stack_sorted(t_stack *stack)
{
	int	i;

	i = stack->nbr;
	while (stack)
	{
		if (i > stack->nbr)
			return (0);
		i = stack->nbr;
		stack = stack->next;
	}
	return (1);
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
