/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utility1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaled <khaled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:16:44 by khaled            #+#    #+#             */
/*   Updated: 2024/06/30 22:12:34 by khaled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(int n, int m)
{
	if (n > m)
		return (n);
	return (m);
}

int	min_cost(int l_a, int l_b, int i_a, int i_b)
{
	if (i_a < i_b)
	{
		if (i_b <= max(l_a - i_a, l_b - i_b) && i_b < i_a + l_b - i_b)
			return (i_b);
		if (i_a + l_b - i_b <= i_b)
		{
			if (i_a + l_b - i_b <= max(l_a - i_a, l_b - i_b))
				return (i_a + l_b - i_b);
		}
		return (max(l_a - i_a, l_b - i_b));
	}
	if (i_a <= max(l_a - i_a, l_b - i_b) && i_a <= i_b + l_a - i_a)
		return (i_a);
	if (i_b + l_a - i_a <= i_a && i_b + l_a - i_a < max(l_a - i_a, l_b - i_b))
		return (i_b + l_a - i_a);
	return (max(l_a - i_a, l_b - i_b));
}

void	cost_calculator(t_stack *a, t_stack *b)
{
	int		len_a;
	int		len_b;
	t_stack	*temp;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		temp = find_nb(b, a->target);
		a -> cost = min_cost(len_a, len_b, a -> index, temp -> index);
		a = a->next;
	}
}
