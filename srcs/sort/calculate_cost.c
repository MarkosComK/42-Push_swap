/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:14:06 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/31 10:16:01 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_pos(t_stack *stack)
{
	int		target;
	int		attr[2];
	t_stack	*tmp;

	tmp = stack_first(stack);
	attr[0] = -1;
	attr[1] = 0;
	target = tmp->nbr;
	while (++attr[0] < stack_size(stack))
	{
		if (tmp->nbr < target)
		{
			target = tmp->nbr;
			attr[1] = attr[0];
		}
		tmp = tmp->next;
	}
	return (attr[1]);
}

int	max_pos(t_stack *stack)
{
	int		target;
	int		attr[2];
	t_stack	*tmp;

	tmp = stack_first(stack);
	attr[0] = -1;
	attr[1] = 0;
	target = tmp->nbr;
	while (++attr[0] < stack_size(stack))
	{
		if (tmp->nbr > target)
		{
			target = tmp->nbr;
			attr[1] = attr[0];
		}
		tmp = tmp->next;
	}
	return (attr[1]);
}

int	node_index(t_stack *stack, int target)
{
	t_stack	*tmp;
	int		index;

	index = 0;
	tmp = stack_first(stack);
	if (stack_size(stack) == 0 || !stack)
		return (-1);
	while (tmp)
	{
		if (tmp->nbr == target)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (-1);
}

void	min_push(t_stack *stack)
{
	int	pos;

	pos = min_pos(stack);
	target_push(stack, pos);
}

void	target_push(t_stack *stack, int pos)
{
	int	len;

	stack = stack_first(stack);
	len = stack_size(stack);
	if (pos <= len / 2)
	{
		while (pos--)
			execute(&stack, NULL, "ra");
	}
	else
	{
		pos = len - pos;
		while (pos--)
			execute(&stack, NULL, "rra");
	}
}
