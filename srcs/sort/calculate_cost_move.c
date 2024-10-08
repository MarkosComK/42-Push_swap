/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:13:52 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/31 10:14:02 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(t_stack *stack_a, t_stack *stack_b, int len)
{
	int		min;
	int		index[2];
	t_stack	*tmp;

	tmp = stack_first(stack_a);
	min = execute_calc(stack_a, stack_b, len, false);
	index[0] = 0;
	index[1] = 0;
	while (tmp)
	{
		if (execute_calc(tmp, stack_b, len, false) < min)
		{
			min = execute_calc(tmp, stack_b, len, false);
			index[1] = index[0];
		}
		tmp = tmp->next;
		index[0]++;
	}
	return (index[1]);
}

int	execute_calc(t_stack *stack_a, t_stack *stack_b, int len, bool return_pos_b)
{
	int	nmoves;
	int	pos[2];

	if ((stack_a->nbr < stack_min(stack_b))
		|| (stack_a->nbr > stack_max(stack_b)))
	{
		pos[0] = node_index(stack_a, stack_a->nbr);
		pos[1] = max_pos(stack_b);
		if (return_pos_b == true)
			nmoves = pos[1];
		else
			nmoves = (lcm(pos, stack_size(stack_a), stack_size(stack_b), false)
					+ 1);
	}
	else
		nmoves = calc(stack_a, stack_b, len, return_pos_b);
	return (nmoves);
}

int	calc(t_stack *stack_a, t_stack *stack_b, int len, bool return_pos_b)
{
	t_stack	*tmp;
	int		nmoves_to_top[2];
	int		target;

	nmoves_to_top[0] = node_index(stack_a, stack_a->nbr);
	tmp = stack_first(stack_b);
	if (stack_b)
	{
		target = tmp->nbr;
		while (tmp)
		{
			if ((tmp->nbr > target && tmp->nbr < stack_a->nbr)
				|| (tmp->nbr < stack_a->nbr
					&& target > stack_a->nbr))
				target = tmp->nbr;
			tmp = tmp->next;
		}
		nmoves_to_top[1] = node_index(stack_b, target);
		if (return_pos_b == true)
			return (nmoves_to_top[1]);
		else
			return (lcm(nmoves_to_top, len, stack_size(stack_b), false) + 1);
	}
	return (nmoves_to_top[0] + 1);
}

int	lcm(int pos[2], int len_a, int len_b, bool return_move)
{
	int	distances[4];
	int	temp_pos_b;

	temp_pos_b = -1;
	if (pos[1] == 0)
	{
		temp_pos_b = pos[1];
		pos[1] = pos[0];
	}
	if (pos[0] < pos[1])
		distances[0] = pos[1];
	else
		distances[0] = pos[0];
	if (len_a - pos[0] < len_b - pos[1])
		distances[1] = (len_b - pos[1]);
	else
		distances[1] = (len_a - pos[0]);
	distances[2] = pos[0] + (len_b - pos[1]);
	distances[3] = (len_a - pos[0]) + pos[1];
	if (temp_pos_b != -1)
		pos[1] = temp_pos_b;
	if (return_move == true)
		return (min_lcm(distances, 4, true));
	else
		return (min_lcm(distances, 4, false));
}

int	min_lcm(int *arr, int len, bool return_index)
{
	int	min;
	int	i;
	int	target_index;

	i = 0;
	target_index = 0;
	min = arr[0];
	while (++i < len)
	{
		if (arr[i] < min && arr[i] >= 0)
		{
			min = arr[i];
			target_index = i;
		}
	}
	if (return_index == true)
		return (target_index);
	else
		return (min);
}
