/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:52:10 by mael-hou          #+#    #+#             */
/*   Updated: 2025/11/22 18:52:12 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stack_size(*stack_a) < 4)
		return (ft_small_sort(stack_a));
	ft_large_sort(stack_a, stack_b);
}
