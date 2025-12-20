/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:52:16 by mael-hou          #+#    #+#             */
/*   Updated: 2025/11/22 18:52:18 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	ft_parse(ac, av, &stack_a);
	if (contain_duplicate(&stack_a))
		error_exit(&stack_a, NULL);
	ft_assign_ranks(&stack_a);
	if (!ft_check_sorted(&stack_a))
		ft_sort(&stack_a, &stack_b);
	ft_stack_clear(&stack_a);
}
