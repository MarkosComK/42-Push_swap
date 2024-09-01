/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:14:30 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/01 11:40:26 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_valid(t_stack *stack_a, char *str, int ac, char **av)
{
	t_stack	*tmp;
	int		nbr;

	tmp = stack_first(stack_a);
	nbr = ft_atoi_ps(str, stack_a, ac, av);
	while (tmp)
	{
		if (tmp->nbr == nbr)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

int	ft_atoi_ps(char *str, t_stack *stack_a, int ac, char **av)
{
	long long int	ans;
	int				result;

	ans = 0;
	result = 1;
	while (is_space(*str))
		str++;
	if (*str == '-')
		result *= -1;
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		ft_error(stack_a, ac, av);
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error(stack_a, ac, av);
		ans = (ans * 10) + (*str - 48);
		str++;
	}
	if ((result * ans) > 2147483647 || (result * ans) < -2147483648)
		ft_error(stack_a, ac, av);
	return (result * ans);
}

bool	is_space(char c)
{
	char	*str;

	str = "\t\n\v\f\r ";
	while (*str)
	{
		if (*str == c)
			return (true);
		str++;
	}
	return (false);
}
