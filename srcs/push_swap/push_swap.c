/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:01:51 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/21 19:28:04 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack *current;

	current = stack;
	while (current)
	{
		ft_printf("%d\n", current->nbr);
		current = current->next; 
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	int		excep_ac;

	if (ac < 2)
		ft_error();
	if (ac == 2)
	{
		excep_ac = split_len(ft_split(av[1], ' '));
		a = stack_exception(excep_ac, ft_split(av[1], ' '));
	}
	else
		a = stack_new(ac, av);
	if (!a || stack_check_dup(a))
	{
		stack_free(a);
		ft_error();
	}
	if (!stack_sorted(a))
		stack_sort(a);
	stack_free(a);
	return (0);
}
