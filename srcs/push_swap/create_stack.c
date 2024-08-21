/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:12:36 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/21 12:38:48 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*stack_new(int ac, char **content)
{
	t_stack	*stack;
	int		i;
	int		j;
	
	stack = (t_stack *)malloc(sizeof(t_stack));
	i = 0;
	j = 0;
	while (i < ac)
	{
		stack_add_tail(&stack, ft_atoi(content[j]));
		i++;
		j++;
	}
	return (stack);
}

t_stack	*stack_add_head(t_stack **stack, void *content)
{
	t_stack *new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	(*stack) = new_node;
	return (new_node);
}

t_stack	*stack_add_tail(t_stack **stack, int content)
{
	t_stack *new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	if (*stack)
	{
		(*stack)->next = new_node;
		new_node->prev = (*stack);
	}
	else
		(*stack) = new_node;
	return (new_node);
}

t_stack	*stack_new_node(int content)
{
	t_stack	*stack_new;

	stack_new = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_new)
		return (NULL);
	stack_new -> nbr = content;
	stack_new -> next = 0;
	stack_new -> prev = 0;
	return (stack_new);
}
