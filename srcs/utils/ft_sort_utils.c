/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:52:07 by mael-hou          #+#    #+#             */
/*   Updated: 2025/11/22 18:55:44 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos_of_min_rank(t_stack *s)
{
	int	min_rank;
	int	pos;
	int	i;

	min_rank = INT_MAX;
	pos = 0;
	i = 0;
	while (s)
	{
		if (s->rank < min_rank)
		{
			min_rank = s->rank;
			pos = i;
		}
		s = s->next;
		i++;
	}
	return (pos);
}

int	get_target_in_a(t_stack *a, int rank_b)
{
	t_stack	*curr;
	int		target_pos;
	int		target_rank;
	int		pos;

	target_rank = INT_MAX;
	target_pos = 0;
	curr = a;
	pos = 0;
	while (curr)
	{
		if (curr->rank > rank_b && curr->rank < target_rank)
		{
			target_rank = curr->rank;
			target_pos = pos;
		}
		curr = curr->next;
		pos++;
	}
	if (target_rank != INT_MAX)
		return (target_pos);
	return (get_pos_of_min_rank(a));
}

void	move_node_to_top_a(t_stack **a, int pos)
{
	int	len;

	len = ft_stack_size(*a);
	if (pos <= len / 2)
	{
		while (pos-- > 0)
			ra(a, 1);
	}
	else
	{
		while (pos++ < len)
			rra(a, 1);
	}
}

int	get_pos_of_max_rank(t_stack *s)
{
	int	max_rank;
	int	pos;
	int	i;

	max_rank = INT_MIN;
	pos = 0;
	i = 0;
	while (s)
	{
		if (s->rank > max_rank)
		{
			max_rank = s->rank;
			pos = i;
		}
		s = s->next;
		i++;
	}
	return (pos);
}

int	get_pos_by_rank(t_stack *s, int rank)
{
	int	i;

	i = 0;
	while (s)
	{
		if (s->rank == rank)
			return (i);
		s = s->next;
		i++;
	}
	return (-1);
}
