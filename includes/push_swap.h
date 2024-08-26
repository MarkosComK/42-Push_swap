/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:03:40 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/26 14:33:45 by marsoare         ###   ########.fr       */
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

# define SA 1
# define SB 2
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RRA 8
# define RRB 9

typedef struct s_stack
{
	long			nbr;
	long			index;
	long			biggest;
	struct s_stack	*next;
	struct s_stack	*prev;
}			t_stack;

void	ft_error(void);

//srcs/operations/
//swap.c
void	swap(t_stack **stack, int move);
void	swap_swap(t_stack **stack_a, t_stack **stack_b);
//push.c
void	push(t_stack **stack_1, t_stack **stack_2, int move);
//rotate.c
void	rotate(t_stack **stack, int move);
void	reverse_rotate(t_stack **stack, int move);
void	rotate_rotate(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_rotate(t_stack **stack_a, t_stack **stack_b);

//srcs/sort
//calculate_cost.c
int		calculate_cost(t_stack **stack_a, t_stack **stack_b);
//stack_sort.c
void	stack_sort(t_stack **stack);
void	stack_sort_b(t_stack **stack_a, t_stack **stack_b);
void	stack_sort_ten(t_stack **stack_a, t_stack **stack_b);
void	stack_sort_tree(t_stack **stack_a);

//srcs/stack
//stack_create.c
t_stack	*stack_exception(int size, char **content);
t_stack	*stack_new(int ac, char **content);
t_stack	*stack_add_head(t_stack **stack, int content);
t_stack	*stack_add_tail(t_stack **stack, int content);
t_stack	*stack_new_node(int content);
//stack_free.c
void	stack_free(t_stack *stack);
//stack_utils.c
int		stack_check_dup(t_stack *stack);
int		stack_sorted(t_stack *stack);
int		stack_size(t_stack *stack);
t_stack	*stack_last(t_stack *stack);
//stack_utils_values.c
int		stack_min(t_stack *stack);
int		stack_max(t_stack *stack);
int		stack_n_is_min(t_stack *stack);
int		stack_n_is_max(t_stack *stack);
//srcs/utils
//utils.c
void	print_stack(t_stack *stack);
int		split_len(char	**tmp);

#endif
