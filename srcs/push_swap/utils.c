/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:01:25 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/21 17:02:22 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

int	split_len(char **tmp)
{
	int	i;

	i = 0;
	while(tmp[i])
		i++;
	while (*tmp)
		free(*tmp++);
	free(tmp);
	return (i);
}
