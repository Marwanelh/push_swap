/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:51:55 by mael-hou          #+#    #+#             */
/*   Updated: 2025/12/01 18:35:12 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, int *pos_a, int *pos_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_stack_size(*a);
	len_b = ft_stack_size(*b);
	if (*pos_a <= len_a / 2 && *pos_b <= len_b / 2)
	{
		while (*pos_a > 0 && *pos_b > 0)
		{
			rr(a, b, 1);
			(*pos_a)--;
			(*pos_b)--;
		}
	}
	else if (*pos_a > len_a / 2 && *pos_b > len_b / 2)
	{
		while (*pos_a < len_a && *pos_b < len_b)
		{
			rrr(a, b, 1);
			(*pos_a)++;
			(*pos_b)++;
		}
	}
}

static void	move_node_to_top_b(t_stack **b, int pos)
{
	int	len;

	len = ft_stack_size(*b);
	if (pos <= len / 2)
	{
		while (pos-- > 0)
			rb(b, 1);
	}
	else
	{
		while (pos++ < len)
			rrb(b, 1);
	}
}

static void	execute_move(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	rotate_both(a, b, &pos_a, &pos_b);
	move_node_to_top_a(a, pos_a);
	move_node_to_top_b(b, pos_b);
}

static void	move_b_to_a(t_stack **a, t_stack **b)
{
	int	pos_a;

	while (*b)
	{
		pos_a = get_target_in_a(*a, (*b)->rank);
		move_node_to_top_a(a, pos_a);
		pa(a, b, 1);
	}
}

void	ft_large_sort(t_stack **a, t_stack **b)
{
	int	pos_a;
	int	pos_b;

	if (ft_stack_size(*a) > 3 && !ft_check_sorted(a))
		pb(a, b, 1);
	if (ft_stack_size(*a) > 3 && !ft_check_sorted(a))
		pb(a, b, 1);
	while (ft_stack_size(*a) > 3 && !ft_check_sorted(a))
	{
		pos_a = find_cheapest_pos_a(*a, *b, &pos_b);
		execute_move(a, b, pos_a, pos_b);
		pb(a, b, 1);
	}
	ft_sort_three(a);
	move_b_to_a(a, b);
	move_node_to_top_a(a, get_pos_of_min_rank(*a));
}
