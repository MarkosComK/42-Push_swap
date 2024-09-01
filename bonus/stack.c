/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:44:08 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/01 11:47:56 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*stack_first(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->prev)
		stack = stack->prev;
	return (stack);
}
