/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fnct1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaled <khaled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 23:36:35 by khaled            #+#    #+#             */
/*   Updated: 2024/06/30 23:44:19 by khaled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_first(t_stack **stack)
{
	return ((*stack)->nb);
}

int	find_last_int(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack->nb);
}

int	exist_duplicate(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nb == n)
			return (1);
		a = a->next;
	}
	return (0);
}

int	is_sorted(t_stack *a)
{
	if (!a)
		return (1);
	if (stack_len(a) < 2)
		return (1);
	while (a->next)
	{
		if (a->nb > a->next->nb)
			return (0);
		a = a->next;
	}
	return (1);
}

int	find_max(t_stack *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = -2147483648;
	while (stack)
	{
		if (stack -> nb > max)
			max = stack -> nb;
		stack = stack->next;
	}
	return (max);
}
