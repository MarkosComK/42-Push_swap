/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 09:45:43 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/01 09:48:36 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		size;
	t_stack	*tmp;

	size = 0;
	tmp = stack_first(stack);
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
