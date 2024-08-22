/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:03:40 by marsoare          #+#    #+#             */
/*   Updated: 2024/08/22 16:12:47 by marsoare         ###   ########.fr       */
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

#define SA 1
#define SB 2
#define PA 4
#define PB 5
#define RA 6
#define RB 7

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
//stack_utils.c
int		stack_n_is_min(t_stack *stack);
int		stack_n_is_max(t_stack *stack);
int		stack_check_dup(t_stack *stack);
int		stack_sorted(t_stack *stack);
int		stack_size(t_stack *stack);
void	stack_free(t_stack *stack);
//stack_sort.c
void	stack_sort(t_stack **stack);
void	stack_sort_b(t_stack **stack_a, t_stack **stack_b);
void	stack_sort_tree(t_stack **stack_a);
//swap.c
void	swap(t_stack **stack, int move);
//push.c
void	push(t_stack **stack_1, t_stack **stack_2, int move);
//rotate.c
void	rotate(t_stack **stack, int move);
//utils.c
void	print_stack(t_stack *stack);
int		split_len(char	**tmp);

#endif
