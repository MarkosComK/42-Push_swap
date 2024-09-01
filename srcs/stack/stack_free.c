/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:44:16 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/01 10:34:35 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_free(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	stack = stack_first(stack);
	while (stack)
	{
		tmp = (stack)->next;
		(stack)->nbr = 0;
		free(stack);
		stack = tmp;
	}
}
