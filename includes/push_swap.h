/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:52:35 by mael-hou          #+#    #+#             */
/*   Updated: 2025/12/01 18:34:02 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../srcs/gnl/get_next_line.h"
# include <limits.h>

typedef struct s_stack
{
	long			nbr;
	long			rank;
	struct s_stack	*next;
}					t_stack;

void				ft_error(void);
void				ft_print_str(char *str);

// --- List Utils ---
t_stack				*ft_stack_new(long nbr);
int					ft_stack_size(t_stack *stack);
void				ft_stackadd_back(t_stack **head, t_stack *new);
void				ft_stackadd_front(t_stack **head, t_stack *new);
t_stack				*ft_stacklast(t_stack *head);
void				ft_stack_clear(t_stack **stack);
void				print_stack(t_stack *stack);
void				print_all_stack(t_stack *stack_a, t_stack *stack_b);
int					ft_min(t_stack *stack);
int					ft_max(t_stack *stack);

// --- Instructions ---
void				sa(t_stack **stack_a, int shouldPrint);
void				sb(t_stack **stack_b, int shouldPrint);
void				ss(t_stack **stack_a, t_stack **stack_b, int shouldPrint);
void				pa(t_stack **stack_a, t_stack **stack_b, int shouldPrint);
void				pb(t_stack **stack_a, t_stack **stack_b, int shouldPrint);
void				ra(t_stack **stack, int shouldPrint);
void				rb(t_stack **stack, int shouldPrint);
void				rr(t_stack **stack_a, t_stack **stack_b, int shouldPrint);
void				rra(t_stack **stack, int shouldPrint);
void				rrb(t_stack **stack, int shouldPrint);
void				rrr(t_stack **stack_a, t_stack **stack_b, int shouldPrint);

// --- Parsing & Validation Utils ---
int					is_valid_nbr_str(const char *str);
void				error_exit(t_stack **stack_a, t_stack **stack_b);
void				ft_parse(int argc, char **argv, t_stack **stack);
int					ft_sub_parse(char *str, t_stack **stack);
void				ft_args_parse(int argc, char **argv, t_stack **stack);

int					contain_duplicate(t_stack **stack);
int					ft_check_sorted(t_stack **stack);

// --- Sorting "Brain" Utils ---
void				ft_assign_ranks(t_stack **stack);
void				ft_sort(t_stack **stack_a, t_stack **stack_b);
void				ft_small_sort(t_stack **stack_a);
void				ft_sort_three(t_stack **stack);
void				ft_large_sort(t_stack **stack_a, t_stack **stack_b);

// --- Move & Cost Utils ---
int					get_pos_of_min_rank(t_stack *s);
int					get_pos_of_max_rank(t_stack *s);
int					get_pos_by_rank(t_stack *s, int rank);
int					get_target_in_b(t_stack *b, int rank_a);
int					calc_cost(int pos_a, int pos_b, int len_a, int len_b);
int					find_cheapest_pos_a(t_stack *a, t_stack *b,
						int *target_pos_in_b);

// --- Helper Functions for Moves ---
int					get_target_in_a(t_stack *a, int rank_b);
void				move_node_to_top_a(t_stack **a, int pos);

#endif