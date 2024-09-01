/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:01:51 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/01 14:01:37 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(t_stack *stack_a, int ac, char **av)
{
	int		i;

	i = 0;
	if (ac < 2)
		ft_error(stack_a, ac, av);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	if (ac == 2)
		i = -1;
	while (av[++i])
	{
		if (is_valid(stack_a, av[i], ac, av) == false)
			ft_error(stack_a, ac, av);
		stack_a = stack_add_node(stack_a, ft_atoi(av[i]));
	}
	if (ac == 2)
		free_av(av);
	return (stack_a);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = create_stack(stack_a, ac, av);
	stack_sort(stack_a, stack_b);
	stack_free(stack_a);
	stack_free(stack_b);
	return (0);
}
