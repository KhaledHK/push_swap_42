/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaled <khaled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:07:17 by khaled            #+#    #+#             */
/*   Updated: 2024/07/01 20:14:54 by khaled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_operation(t_stack **a, t_stack **b, char *line)
{
	if (ft_strcmp(line, "ra\n") == 0)
	{
		ra(a, 0);
		return (1);
	}
	if (ft_strcmp(line, "rb\n") == 0)
	{
		rb(b, 0);
		return (1);
	}
	if (ft_strcmp(line, "rr\n") == 0)
	{
		rab(a, b, 0);
		return (1);
	}
	if (ft_strcmp(line, "rra\n") == 0)
	{
		rra(a, 0);
		return (1);
	}
	return (0);
}

int	r_rotate_operation(t_stack **a, t_stack **b, char *line)
{
	if (ft_strcmp(line, "rrb\n") == 0)
	{
		rrb(b, 0);
		return (1);
	}
	if (ft_strcmp(line, "rrr\n") == 0)
	{
		rrab(a, b, 0);
		return (1);
	}
	if (ft_strcmp(line, "sa\n") == 0)
	{
		sa(a, 0);
		return (1);
	}
	if (ft_strcmp(line, "sb\n") == 0)
	{
		sb(a, 0);
		return (1);
	}
	return (0);
}

int	excute_line_operation(t_stack **a, t_stack **b, char *line)
{
	if (rotate_operation(a, b, line) || r_rotate_operation(a, b, line))
		return (1);
	if (ft_strcmp(line, "ss\n") == 0)
	{
		sab(a, b, 0);
		return (1);
	}
	if (ft_strcmp(line, "pa\n") == 0)
	{
		pb(a, b, 0);
		return (1);
	}
	if (ft_strcmp(line, "pb\n") == 0)
	{
		pa(a, b, 0);
		return (1);
	}
	return (0);
}

void	excute_operation(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (excute_line_operation(a, b, line) == 0)
		{
			free(line);
			put_error();
		}
		free (line);
		line = get_next_line(0);
	}
	if (!is_sorted(*a) || stack_len(*b) != 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && word_count(argv[1]) < 2) || !argv[1])
		put_error();
	else if (argc == 2)
		argv = split(argv[1]);
	stack_len_print(a);
	init_stack_a(&a, argv + 1);
	excute_operation(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
