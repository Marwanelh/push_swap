/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:51:15 by mael-hou          #+#    #+#             */
/*   Updated: 2025/12/01 18:40:38 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b, int shouldPrint)
{
	t_stack	*tmp;

	if (!stack_b || !(*stack_b))
		return ;
	tmp = *stack_b;
	*stack_b = tmp->next;
	tmp->next = NULL;
	ft_stackadd_front(stack_a, tmp);
	if (shouldPrint)
		ft_print_str("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b, int shouldPrint)
{
	t_stack	*tmp;

	if (!stack_a || !(*stack_a))
		return ;
	tmp = *stack_a;
	*stack_a = tmp->next;
	tmp->next = NULL;
	ft_stackadd_front(stack_b, tmp);
	if (shouldPrint)
		ft_print_str("pb\n");
}
