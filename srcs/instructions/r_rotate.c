/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:51:19 by mael-hou          #+#    #+#             */
/*   Updated: 2025/12/01 17:39:13 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack, int shouldprint)
{
	t_stack	*head;
	t_stack	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	head = *stack;
	second_last = head;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	*stack = second_last->next;
	second_last->next = NULL;
	(*stack)->next = head;
	if (shouldprint)
		ft_print_str("rra\n");
}

void	rrb(t_stack **stack, int shouldprint)
{
	t_stack	*head;
	t_stack	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	head = *stack;
	second_last = head;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	*stack = second_last->next;
	second_last->next = NULL;
	(*stack)->next = head;
	if (shouldprint)
		ft_print_str("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int shouldPrint)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (shouldPrint)
		ft_print_str("rrr\n");
}
