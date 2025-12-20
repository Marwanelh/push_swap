/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:51:52 by mael-hou          #+#    #+#             */
/*   Updated: 2025/11/22 18:56:11 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_str(char *str)
{
	ft_putstr_fd(str, 1);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	error_exit(t_stack **stack_a, t_stack **stack_b)
{
	ft_stack_clear(stack_a);
	ft_stack_clear(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}
