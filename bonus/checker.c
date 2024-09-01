/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:50:44 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/01 11:54:35 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	validate(t_stack *stack_a, t_stack *stack_b)
{
	write(STDOUT_FILENO, BOLD, 4);
	if (stack_sorted(stack_a) && stack_size(stack_b) == 0)
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	write(STDOUT_FILENO, RESET, 4);
}

t_stack	*create_stack(t_stack *stack_a, char **av)
{
	int		i;

	i = 0;
	while (av[++i])
	{
		if (is_valid(stack_a, av[i]) == false)
			ft_error(stack_a);
		stack_a = stack_add_node(stack_a, ft_atoi(av[i]));
	}
	return (stack_a);
}

int	main(int ac, char **av)
{
	char	*line;
	t_stack	*stack_a;
	t_stack	*stack_b;

	(void) ac;
	stack_a = NULL;
	stack_b = NULL;
	stack_a = create_stack(stack_a, av);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		execute(&stack_a, &stack_b, line);
		free(line);
	}
	validate(stack_a, stack_b);
	free(line);
	return (0);
}
