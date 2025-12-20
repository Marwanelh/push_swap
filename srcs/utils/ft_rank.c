/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rank.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:52:01 by mael-hou          #+#    #+#             */
/*   Updated: 2025/11/22 18:56:01 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_next_min(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*min_node;
	long	min_nbr;

	min_node = NULL;
	min_nbr = LONG_MAX;
	curr = *stack;
	while (curr)
	{
		if (curr->nbr < min_nbr && curr->rank == 0)
		{
			min_nbr = curr->nbr;
			min_node = curr;
		}
		curr = curr->next;
	}
	return (min_node);
}

void	ft_assign_ranks(t_stack **stack)
{
	t_stack	*node;
	int		curr_rank;
	int		stack_size;

	stack_size = ft_stack_size(*stack);
	curr_rank = 1;
	while (curr_rank <= stack_size)
	{
		node = find_next_min(stack);
		if (node)
			node->rank = curr_rank;
		curr_rank++;
	}
}
