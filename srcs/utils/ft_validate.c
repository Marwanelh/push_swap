/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:52:13 by mael-hou          #+#    #+#             */
/*   Updated: 2025/11/22 18:55:50 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_nbr_str(const char *str)
{
	int	i;

	i = 0;
	if (!str || str[i] == 0)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == 0)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	contain_duplicate(t_stack **stack)
{
	t_stack	*outer;
	t_stack	*inner;

	outer = *stack;
	while (outer)
	{
		inner = outer->next;
		while (inner)
		{
			if (outer->nbr > INT_MAX || outer->nbr < INT_MIN)
				return (1);
			if (outer->nbr == inner->nbr)
				return (1);
			inner = inner->next;
		}
		outer = outer->next;
	}
	return (0);
}
