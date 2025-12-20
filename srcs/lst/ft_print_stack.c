/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:51:27 by mael-hou          #+#    #+#             */
/*   Updated: 2025/11/22 18:56:34 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*curr;

	curr = stack;
	while (curr)
	{
		ft_putstr_fd("Rank : ", 1);
		ft_putnbr_fd(curr->rank, 1);
		ft_putstr_fd(" -> ", 1);
		ft_putnbr_fd(curr->nbr, 1);
		ft_putchar_fd('\n', 1);
		curr = curr->next;
	}
}

void	print_all_stack(t_stack *stack_a, t_stack *stack_b)
{
	ft_putstr_fd("stack_a Size : ", 1);
	ft_putnbr_fd(ft_stack_size(stack_a), 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("----------\n", 1);
	print_stack(stack_a);
	ft_putstr_fd("----------\n", 1);
	ft_putstr_fd("stack_b Size : ", 1);
	ft_putnbr_fd(ft_stack_size(stack_b), 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("----------\n", 1);
	print_stack(stack_b);
	ft_putstr_fd("----------\n", 1);
}
