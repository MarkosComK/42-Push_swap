/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:10:43 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/22 18:20:48 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack, int move)
{
	t_stack	*tmp;

	if (!*stack|| !((*stack)->next))
		return ;
	tmp = *stack;
	*stack = stack_last(*stack);
	(*stack)->next = tmp;
	*stack = tmp->next;
	tmp->next = NULL;
	if (move == RA)
		write(1, "ra\n", 3);
	if (move == RB)
		write(1, "rb\n", 3);
}

void	r_rotate(t_stack **stack, int move)
{
	t_stack	*tmp;
	int		i;

	if (!*stack || !(*stack)->next)
		return ;
	i = 0;
	tmp = *stack;
	while ((*stack)->next)
	{
		*stack = (*stack)->next;
		i++;
	}
	(*stack)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (move == RRA)
		write(1, "rra\n", 4);
	if (move == RRB)
		write(1, "rra\n", 4);
}
