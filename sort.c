/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khkhaled <khkhaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 21:20:01 by khaled            #+#    #+#             */
/*   Updated: 2024/07/02 12:27:05 by khkhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	int	len;

	len = stack_len(*a);
	if (len-- >= 4 && is_sorted(a[0]) == 0)
		pa(a, b, 1);
	if (len-- >= 4 && is_sorted(a[0]) == 0)
		pa(a, b, 1);
	while (len-- >= 4 && is_sorted(a[0]) == 0)
	{
		set_index_median(*a);
		set_index_median(*b);
		set_target_min(*a,*b);
		cost_calculator(*a, *b);
		push_for_a(a, b);
	}
	sort_small(a);
	while (*b)
	{
		set_index_median(*a);
		set_index_median(*b);
		set_target_max(*a, *b);
		push_for_b(a, b);
	}
	set_index_median(*a);
	min_to_top(a);
}

void	set_index_median(t_stack *s)
{
	int	median;
	int	count;

	if (!s)
		return ;
	median = stack_len(s) / 2;
	count = 0;
	while (s)
	{
		s->index = count;
		if (count <= median)
			s->median_top = 1;
		else
			s->median_top = 0;
		s = s->next;
		count++;
	}
}

void	set_target_min(t_stack *a, t_stack *b)
{
	t_stack	*temp;

	temp = b;
	while (a)
	{
		a -> target = -2147483648;
		while (b)
		{
			if (b -> nb < a -> nb && b -> nb > a->target)
				a->target = b -> nb;
			b = b->next;
		}
		b = temp;
		if (a->target == -2147483648)
			a->target = find_max(b);
		a = a->next;
	}
}
