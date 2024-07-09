/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utility2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaled <khaled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:54:35 by khaled            #+#    #+#             */
/*   Updated: 2024/06/30 23:14:54 by khaled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_for_a(t_stack **a, t_stack **b)
{
	int	target_a;
	int	target_b;
	int	test_a;
	int	test_b;

	target_a = find_min_cost(*a)->nb;
	test_a = find_min_cost(*a)->median_top;
	target_b = find_nb(*b, find_min_cost(*a)->target)->nb;
	test_b = find_nb(*b, find_min_cost(*a)->target)->median_top;
	if (test_a && test_b)
		push_to_top(a, b, target_a, target_b);
	else if (!(test_a) && !(test_b))
		push_to_button(a, b, target_a, target_b);
	push_a_to_top_x(a, target_a, test_a);
	push_b_to_top_x(b, target_b, test_b);
	pa(a, b, 1);
}

void	push_to_top(t_stack **a, t_stack **b, int t_a, int t_b)
{
	while (a[0]->nb != t_a && b[0]->nb != t_b)
	{
		rab(a, b, 1);
	}
	set_index_median(*a);
	set_index_median(*b);
}

void	push_to_button(t_stack **a, t_stack **b, int t_a, int t_b)
{
	while (a[0]->nb != t_a && b[0]->nb != t_b)
		rrab(a, b, 1);
	set_index_median(*a);
	set_index_median(*b);
}

void	push_a_to_top_x(t_stack **a, int nb, int test)
{
	while (a[0]->nb != nb)
	{
		if (test)
		{
			ra(a, 1);
		}
		else
			rra(a, 1);
	}
}

void	push_b_to_top_x(t_stack **b, int nb, int test)
{
	while (b[0]-> nb != nb)
	{
		if (test)
		{
			rb(b, 1);
		}
		else
		{
			rrb(b, 1);
		}
	}
}
