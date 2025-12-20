/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 23:04:57 by mael-hou          #+#    #+#             */
/*   Updated: 2025/12/01 17:23:05 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target_in_b(t_stack *b, int rank_a)
{
	t_stack	*curr;
	int		target_pos;
	int		target_rank;
	int		pos;

	target_rank = INT_MIN;
	target_pos = 0;
	curr = b;
	pos = 0;
	while (curr)
	{
		if (curr->rank < rank_a && curr->rank > target_rank)
		{
			target_rank = curr->rank;
			target_pos = pos;
		}
		curr = curr->next;
		pos++;
	}
	if (target_rank != INT_MIN)
		return (target_pos);
	return (get_pos_of_max_rank(b));
}

static int	cost_comb(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	calc_cost(int pos_a, int pos_b, int len_a, int len_b)
{
	int	cost_rarb;
	int	cost_rrarrb;
	int	cost_rarrb;
	int	cost_rrarb;
	int	min;

	cost_rarb = cost_comb(pos_a, pos_b);
	cost_rrarrb = cost_comb(len_a - pos_a, len_b - pos_b);
	cost_rarrb = pos_a + (len_b - pos_b);
	cost_rrarb = (len_a - pos_a) + pos_b;
	min = cost_rarb;
	if (cost_rrarrb < min)
		min = cost_rrarrb;
	if (cost_rarrb < min)
		min = cost_rarrb;
	if (cost_rrarb < min)
		min = cost_rrarb;
	return (min);
}

int	find_cheapest_pos_a(t_stack *a, t_stack *b, int *target_pos_in_b)
{
	t_stack	*curr;
	int		best_cost;
	int		best_pos_a;
	int		size[2];
	int		pos[2];

	size[0] = ft_stack_size(a);
	size[1] = ft_stack_size(b);
	best_cost = INT_MAX;
	best_pos_a = 0;
	pos[0] = 0;
	curr = a;
	while (curr)
	{
		pos[1] = get_target_in_b(b, curr->rank);
		if (calc_cost(pos[0], pos[1], size[0], size[1]) < best_cost)
		{
			best_cost = calc_cost(pos[0], pos[1], size[0], size[1]);
			best_pos_a = pos[0];
			*target_pos_in_b = pos[1];
		}
		curr = curr->next;
		pos[0]++;
	}
	return (best_pos_a);
}
