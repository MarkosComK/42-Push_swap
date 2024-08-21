/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:12:36 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/21 17:02:51 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*stack_exception(int size, char **content)
{
	t_stack	*stack;
	int		i;
	int		j;
	
	stack = stack_new_node(ft_atoi(content[0]));
	i = 1;
	while (i < size)
	{
		j = ft_atoi(content[i]);
		stack_add_tail(&stack, j);
		i++;
	}
	while (*content)
		free(*content++);
	free(content);
	return (stack);
}

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
		stack_add_tail(&stack, j);
		i++;
	}
	return (stack);
}

t_stack	*stack_add_head(t_stack **stack, int content)
{
	t_stack *new_node;

	new_node = stack_new_node(content);
	if (!new_node)
		return (NULL);
	new_node->next = *stack;
	(*stack)->prev = new_node;
	return (new_node);
}

t_stack	*stack_add_tail(t_stack **stack, int content)
{
	t_stack *new_node;
	t_stack	*last;

	new_node = stack_new_node(content);
	if (!new_node)
		return (NULL);
	last = stack_last(*stack);
	last->next = new_node;
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
