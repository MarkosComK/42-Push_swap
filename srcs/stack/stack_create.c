/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:12:36 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/22 13:17:08 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int ac, char **content)
{
	t_stack	*stack;
	int		i;
	int		j;

	stack = stack_new_node(ft_atoi(content[1]));
	i = 2;
	while (i < ac)
	{
		j = ft_atoi(content[i]);
		stack_add_tail(stack, j);
		i++;
	}
	return (stack);
}

t_stack	*stack_add_head(t_stack **stack, int content)
{
	t_stack	*new_node;

	new_node = stack_new_node(content);
	if (!new_node)
		return (NULL);
	new_node->next = *stack;
	(*stack)->prev = new_node;
	return (new_node);
}

t_stack	*stack_add_tail(t_stack *stack, int content)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = stack_new_node(content);
	if (!new_node)
		return (NULL);
	last = stack_last(stack);
	last->next = new_node;
	new_node->prev = (stack);
	return (new_node);
}

t_stack	*stack_add_node(t_stack *node, int content)
{
	t_stack	*new;

	new = stack_new_node(content);
	if (!new)
		return (NULL);
	if (!node)
		return (new);
	node->next = new;
	new->prev = node;
	return (new);
}

t_stack	*stack_new_node(int content)
{
	t_stack	*stack_new;

	stack_new = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_new)
		return (NULL);
	stack_new -> nbr = content;
	stack_new -> next = NULL;
	stack_new -> prev = NULL;
	return (stack_new);
}
