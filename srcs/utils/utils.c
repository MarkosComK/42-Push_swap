/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:01:25 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/01 11:34:01 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack_first(stack);
	ft_printf("STACK: \n");
	while (current)
	{
		ft_printf("%d\n", current->nbr);
		current = current->next;
	}
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

void	ft_error(t_stack *stack, int ac, char **av)
{
	if (ac == 2)
		free_av(av);
	stack_free(stack);
	write(2, "Error\n", 6);
	exit (1);
}

int	split_len(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		i++;
	while (*tmp)
		free(*tmp++);
	free(tmp);
	return (i);
}

void	free_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}
