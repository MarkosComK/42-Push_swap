/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:01:25 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/22 14:21:24 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_error(void)
{
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
