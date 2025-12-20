/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:51:22 by mael-hou          #+#    #+#             */
/*   Updated: 2025/12/01 17:38:54 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack, int shouldprint)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = tmp->next;
	tmp->next = NULL;
	ft_stackadd_back(stack, tmp);
	if (shouldprint)
		ft_print_str("ra\n");
}

void	rb(t_stack **stack, int shouldprint)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = tmp->next;
	tmp->next = NULL;
	ft_stackadd_back(stack, tmp);
	if (shouldprint)
		ft_print_str("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b, int shouldPrint)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (shouldPrint)
		ft_print_str("rr\n");
}
