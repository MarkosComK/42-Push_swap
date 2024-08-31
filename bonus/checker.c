
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:50:44 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/31 13:18:27 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(void)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		ft_printf("CMD: %s\n", line);
		free(line);
	}
	free(line);
	return (0);
}
