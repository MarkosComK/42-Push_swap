
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:50:44 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/31 13:18:27 by marsoare         ###   ########.fr       */
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

void	print_stacks(t_stack *stack1, t_stack *stack2)
{
	t_stack	*current1;
	t_stack	*current2;

	current1 = stack_first(stack1);
	current2 = stack_first(stack2);
	ft_printf("A ----- B\n");
	while (current1 || current2)
	{
		if (current1)
		{
			ft_printf("%i\t", current1->nbr);
			current1 = current1->next;
		}
		else
			ft_printf("\t");
		if (current2)
		{
			ft_printf("%i\n", current2->nbr);
			current2 = current2->next;
		}
		else
			ft_printf("\n");
	}
}

static void	validate(t_stack *stack_a, t_stack *stack_b, bool error)
{
	write(STDOUT_FILENO, BOLD, 4);
	if (!error && stack_sorted(stack_a) && stack_size(stack_b) == 0)
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	write(STDOUT_FILENO, RESET, 4);
}

int	main(int ac, char **av)
{
	char	*line;
	t_stack	*stack_a;
	t_stack	*stack_b;
	bool	error;
	int		i;
	
	(void) ac;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	while (av[++i])
	{
		if (is_valid(stack_a, av[i]) == false)
			ft_error(stack_a);
		stack_a = stack_add_node(stack_a, ft_atoi(av[i]));
	}
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		error = execute(&stack_a, &stack_b, line);
		free(line);
	}
	validate(stack_a, stack_b, error);
	free(line);
	return (0);
}
