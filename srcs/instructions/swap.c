/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:51:25 by mael-hou          #+#    #+#             */
/*   Updated: 2025/12/01 17:44:23 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a, int shouldprint)
{
	t_stack	*tmp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	if (shouldprint)
		ft_print_str("sa\n");
}

void	sb(t_stack **stack_b, int shouldprint)
{
	t_stack	*tmp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	if (shouldprint)
		ft_print_str("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b, int shouldPrint)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (shouldPrint)
		ft_print_str("ss\n");
}
