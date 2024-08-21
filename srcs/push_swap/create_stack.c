/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:12:36 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/21 11:20:50 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	create_stack(int ac, char **av)
{
	int		i;
	int		j;
	t_stack	*a;

	i = 0;
	j = 0;
	if (ac < 2)
		ft_error();
	if (ac == 2);
		//function to convert av[1] to intengers
	else
	{
		while (i < ac)
		{
			j = ft_atoi(av[i]);
			// function to add j to stack stack_add(&a, stack_new_node(j));
			i++;
		}
	}
	return (a);
}
