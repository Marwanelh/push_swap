/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:52:04 by mael-hou          #+#    #+#             */
/*   Updated: 2025/11/22 18:55:58 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **stack)
{
	long	top;
	long	mid;
	long	last;

	top = (*stack)->nbr;
	mid = (*stack)->next->nbr;
	last = (*stack)->next->next->nbr;
	if (top > mid && top > last)
		ra(stack, 1);
	else if (mid > top && mid > last)
		rra(stack, 1);
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(stack, 1);
}

void	ft_small_sort(t_stack **stack_a)
{
	int	len;

	len = ft_stack_size(*stack_a);
	if (ft_check_sorted(stack_a))
		return ;
	if (len == 2)
		sa(stack_a, 1);
	else if (len == 3)
		ft_sort_three(stack_a);
}
