/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:01:51 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/21 16:18:22 by marsoare         ###   ########.fr       */
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

int	split_len(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	t_stack	*a;

	if (ac < 2)
		ft_error();
	if (ac == 2)
		a = stack_new(split_len(ft_split(av[1], ' ')), ft_split(av[1], ' '));
	else
		a = stack_new(ac, av);
	print_stack(a);
	stack_free(a);
	return (0);
}
