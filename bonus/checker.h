/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:46:20 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/31 13:59:29 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	long				nbr;
	struct s_stack		*next;
	struct s_stack		*prev;
}			t_stack;

# define SA 1
# define SB 2
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RRA 8
# define RRB 9

void	swap(t_stack **stack, int move);
void	swap_swap(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **stack_1, t_stack **stack_2, int move);
void	rotate(t_stack **stack, int move);
void	reverse_rotate(t_stack **stack, int move);
void	rotate_rotate(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_rotate(t_stack **stack_a, t_stack **stack_b);

t_stack	*stack_first(t_stack *stack);
t_stack	*stack_last(t_stack *stack);

#endif
