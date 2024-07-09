/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fnct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaled <khaled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 23:23:03 by khaled            #+#    #+#             */
/*   Updated: 2024/06/30 23:42:59 by khaled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	remove_last(t_stack **stack)
{
	t_stack	*current;
	t_stack	*previous;

	current = *stack;
	previous = NULL;
	if (stack == NULL || *stack == NULL)
	{
		return ;
	}
	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
	}
	if (previous == NULL)
	{
		*stack = NULL;
	}
	else
	{
		previous->next = NULL;
	}
	free(current);
}

void	add_last(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->nb = n;
	if (!(*stack))
		*stack = node;
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
	}
}

void	add_first(t_stack **stack, int n)
{
	t_stack	*node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = *stack;
	node->nb = n;
	*stack = node;
}

void	remove_first(t_stack **stack)
{
	t_stack	*node;

	if (!stack)
		return ;
	node = *stack ;
	*stack = stack[0]->next;
	node -> next = NULL;
	node -> nb = 0;
	free(node);
}
