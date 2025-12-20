/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:51:09 by mael-hou          #+#    #+#             */
/*   Updated: 2025/12/01 18:47:19 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	read_stdin(t_stack **stack_a, t_stack **stack_b);
int		check_and_run_input(char *line, t_stack **stack_a, t_stack **stack_b);

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	ft_parse(argc, argv, &stack_a);
	if (contain_duplicate(&stack_a))
		error_exit(&stack_a, NULL);
	read_stdin(&stack_a, &stack_b);
	if (ft_check_sorted(&stack_a) && ft_stack_size(stack_b) == 0)
	{
		ft_print_str("OK\n");
	}
	else
		ft_print_str("KO\n");
	ft_stack_clear(&stack_a);
	ft_stack_clear(&stack_b);
}

void	read_stdin(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (check_and_run_input(line, stack_a, stack_b))
		{
			free(line);
			error_exit(stack_a, stack_b);
		}
		free(line);
		line = get_next_line(0);
	}
}

int	check_and_run_input(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(line, "sa\n", 3))
		return (sa(stack_a, 0), 0);
	if (!ft_strncmp(line, "sb\n", 3))
		return (sb(stack_b, 0), 0);
	if (!ft_strncmp(line, "ss\n", 3))
		return (ss(stack_a, stack_b, 0), 0);
	if (!ft_strncmp(line, "pa\n", 3))
		return (pa(stack_a, stack_b, 0), 0);
	if (!ft_strncmp(line, "pb\n", 3))
		return (pb(stack_a, stack_b, 0), 0);
	if (!ft_strncmp(line, "ra\n", 3))
		return (ra(stack_a, 0), 0);
	if (!ft_strncmp(line, "rb\n", 3))
		return (rb(stack_b, 0), 0);
	if (!ft_strncmp(line, "rr\n", 3))
		return (rr(stack_a, stack_b, 0), 0);
	if (!ft_strncmp(line, "rra\n", 4))
		return (rra(stack_a, 0), 0);
	if (!ft_strncmp(line, "rrb\n", 4))
		return (rrb(stack_b, 0), 0);
	if (!ft_strncmp(line, "rrr\n", 4))
		return (rrr(stack_a, stack_b, 0), 0);
	return (1);
}
