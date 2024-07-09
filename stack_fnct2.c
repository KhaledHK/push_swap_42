/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fnct2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaled <khaled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 23:37:08 by khaled            #+#    #+#             */
/*   Updated: 2024/06/30 23:47:54 by khaled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = 2147483647;
	while (stack)
	{
		if (stack -> nb < min)
			min = stack -> nb;
		stack = stack->next;
	}
	return (min);
}

t_stack	*find_nb(t_stack *stack, int nb)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack -> nb == nb)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_stack	*find_min_cost(t_stack *stack)
{
	int		min;
	t_stack	*temp;

	min = 2147483647;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack -> cost < min)
		{
			min = stack ->cost;
			temp = stack;
		}
		stack = stack->next;
	}
	return (temp);
}

int	stack_len_print(t_stack *stack)
{
	int	count;

	if (!stack)
	{
		return (0);
	}
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

int	stack_len(t_stack *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}
