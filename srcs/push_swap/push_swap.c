/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:01:51 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/21 13:17:50 by marsoare         ###   ########.fr       */
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

	if (ac < 2)
		ft_error();
	/*
	if (ac == 2)
		function_to_handle();
	*/
	a = stack_new(ac, av);
	if (ac < 2)
		ft_error();
	ft_printf("starting");
	print_stack(a);
	return (0);
}
