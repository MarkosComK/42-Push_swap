/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:12:36 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/21 15:06:25 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*stack_new(int ac, char **content)
{
	t_stack	*stack;
	int		i;
	int		j;
	
	stack = (t_stack *)malloc(sizeof(t_stack));
	i = 1;
	j = 1;
	while (i < ac)
	{
		int value = ft_atoi(content[j]);
		if (i == 1)
			stack = stack_new_node(value);
		else
			stack_add_tail(&stack, value);
		i++;
		j++;
	}
	return (stack);
}

t_stack	*stack_add_head(t_stack **stack, int content)
{
	t_stack *new_node;
	(void) content;

	new_node = stack_new_node(content);
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

	new_node = stack_new_node(content);
	if (!new_node)
		return (NULL);
	(*stack)->next = new_node;
	new_node->prev = (*stack);
	return (new_node);
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
