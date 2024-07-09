/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utility3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaled <khaled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:55:55 by khaled            #+#    #+#             */
/*   Updated: 2024/07/01 19:21:47 by khaled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_max(t_stack *a, t_stack *b)
{
	t_stack	*temp;

	temp = a;
	while (b)
	{
		b -> target = 2147483647;
		while (a)
		{
			if (a-> nb > b -> nb && a-> nb < b->target)
				b -> target = a -> nb;
			a = a-> next;
		}
		a = temp;
		if (b->target == 2147483647)
			b->target = find_min(a);
		b = b->next;
	}
}

void	push_for_b(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;

	temp_a = find_nb(*a, b[0]->target);
	while (a[0]->nb != b[0]->target)
	{
		if (temp_a ->median_top)
			ra(a, 1);
		else
			rra(a, 1);
	}
	pb(a, b, 1);
}

void	min_to_top(t_stack **a)
{
	int		min;
	t_stack	*node;

	min = find_min(*a);
	node = find_nb(*a, min);
	while (a[0]->nb != min)
	{
		if (node->median_top)
		{
			ra(a, 1);
		}
		else
			rra(a, 1);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' )
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
