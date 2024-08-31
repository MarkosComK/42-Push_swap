/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:03:40 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/31 10:19:49 by marsoare         ###   ########.fr       */
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
	long				nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
}			t_stack;

typedef struct s_cost_index
{
	int	cost;
	int	index;
}			t_cost_index;


//srcs/check
//check_args.c
bool	is_valid(t_stack *stack_a, char *str);
t_stack	*first_node(t_stack *stack);
bool	is_space(char c);
int		ft_atoi_ps(char *str, t_stack *stack_a);
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
//execution.c
void	execute(t_stack **stack_a, t_stack **stack_b, char *line);
void	multi_execute(t_stack **stack_a, t_stack **stack_b, char *line, int n);
//srcs/sort
//calculate_cost.c
int	min_pos(t_stack *stack);
int	max_pos(t_stack *stack);
void	min_push(t_stack *stack);
void	target_push(t_stack *stack, int pos);
int	node_index(t_stack *stack, int target);
//calculate_cost_move.c
int	execute_calc(t_stack *stack_a, t_stack *stack_b, int len, bool return_pos_b);
int	lcm(int pos[2], int len_a, int len_b, bool return_move);
int	calc(t_stack *stack_a, t_stack *stack_b, int len, bool return_pos_b);
int	min_lcm(int *arr, int len, bool return_index);
int	find_min_index(t_stack *stack_a, t_stack *stack_b, int len);
//stack_sort.c
void	stack_sort(t_stack *stack_a, t_stack *stack_b);
void	sort_five(t_stack *stack_a, t_stack *stack_b, int len);
void	sort_all(t_stack *stack_a, t_stack *stack_b);
void	stack_sort_three(t_stack *stack_a);
int	find_target(t_stack *stack_from, t_stack *stack_to);
//stack_sort_utils.c
void	execute_ps(t_stack **stack_a, t_stack **stack_b, int pos[2], int mode);
void	exec_smt(t_stack **stack_a, t_stack **stack_b, int pos[2], int mode);
void	reverse_pos(t_stack **stack_a, t_stack **stack_b, int pos[2]);

//srcs/stack
//stack_create.c
t_stack	*stack_exception(int size, char **content);
t_stack	*stack_new(int ac, char **content);
t_stack	*stack_add_head(t_stack **stack, int content);
t_stack	*stack_add_tail(t_stack *stack, int content);
t_stack	*stack_add_node(t_stack *node, int content);
t_stack	*stack_new_node(int content);
//stack_free.c
void	stack_free(t_stack *stack);
//stack_utils.c
int		stack_check_dup(t_stack *stack);
int		stack_sorted(t_stack *stack);
int		stack_size(t_stack *stack);
t_stack	*stack_last(t_stack *stack);
t_stack	*stack_first(t_stack *stack);
//stack_utils_values.c
int		stack_min(t_stack *stack);
int		stack_max(t_stack *stack);
int		stack_n_is_min(t_stack *stack);
int		stack_n_is_max(t_stack *stack);
//utils_values.c
int	max(int a, int b);
int	min(int a, int b);
//srcs/utils
//utils.c
void	print_stack(t_stack *stack);
void print_stacks(t_stack *stack1, t_stack *stack2);
int		split_len(char	**tmp);
void	ft_error(t_stack *stack);

#endif
