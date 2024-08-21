/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:03:40 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/21 18:17:20 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}			t_stack;

void	ft_error(void);

//stack_create.c
t_stack	*stack_new(int ac, char **content);
t_stack	*stack_exception(int size, char **content);
t_stack	*stack_new_node(int content);
t_stack	*stack_add_head(t_stack **stack, int content);
t_stack	*stack_add_tail(t_stack **stack, int content);
t_stack	*stack_last(t_stack *stack);
int		stack_check_dup(t_stack *stack);
void	stack_free(t_stack *stack);
//utils.c
int		split_len(char	**tmp);

#endif
