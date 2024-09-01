/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:46:20 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/01 11:40:52 by marsoare         ###   ########.fr       */
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

# define BOLD "\033[1m"
# define BOLD_GREEN "\033[1;32m"
# define BOLD_RED "\033[1;31m"
# define BOLD_BLUE "\033[1;34m"
# define BOLD_YELLOW "\033[1;33m"
# define RESET "\033[0m"
# define BOLD_WHITE "\033[1;37m"

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

void	stack_free(t_stack *stack);
void	ft_error(t_stack *stack);
int		ft_atoi_ps(char *str, t_stack *stack_a);
bool	is_valid(t_stack *stack_a, char *str);

int		stack_sorted(t_stack *stack);
int		stack_size(t_stack *stack);

bool	execute(t_stack **stack_a, t_stack **stack_b, char *line);
#endif
