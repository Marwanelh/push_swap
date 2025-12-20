/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:51:39 by mael-hou          #+#    #+#             */
/*   Updated: 2025/11/22 18:56:25 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackadd_back(t_stack **head, t_stack *new)
{
	t_stack	*tmp;

	if (!head)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	tmp = ft_stacklast(*head);
	tmp->next = new;
	new->next = NULL;
}
