/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:51:58 by mael-hou          #+#    #+#             */
/*   Updated: 2025/11/23 23:29:09 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void	ft_args_parse(int ac, char **av, t_stack **stack)
{
	long	nbr;
	int		i;

	i = 1;
	while (i < ac)
	{
		if (!is_valid_nbr_str(av[i]))
			error_exit(stack, NULL);
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_exit(stack, NULL);
		ft_stackadd_back(stack, ft_stack_new(nbr));
		i++;
	}
}

static void	ft_free_split(char **args, int i)
{
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	ft_sub_parse(char *str, t_stack **stack)
{
	char	**args;
	long	nbr;
	int		i;

	args = ft_split(str, ' ');
	if (!args)
		return (1);
	i = 0;
	while (args[i])
	{
		nbr = ft_atol(args[i]);
		if (!is_valid_nbr_str(args[i]) || nbr > INT_MAX || nbr < INT_MIN)
		{
			ft_free_split(args, i);
			return (1);
		}
		ft_stackadd_back(stack, ft_stack_new(nbr));
		free(args[i]);
		i++;
	}
	free(args);
	return (0);
}

void	ft_parse(int ac, char **av, t_stack **stack)
{
	if (ac == 2)
	{
		if (ft_sub_parse(av[1], stack) == 1)
			error_exit(stack, NULL);
	}
	else
	{
		ft_args_parse(ac, av, stack);
	}
}
