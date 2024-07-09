/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaled <khaled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:36:13 by khkhaled          #+#    #+#             */
/*   Updated: 2024/07/01 19:28:11 by khaled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*node;
	t_stack	*node2;

	if (!stack || stack_len(*stack) < 2)
		return ;
	node = stack[0];
	node2 = stack[0]->next;
	node -> next = node2->next;
	node2->next = node;
	stack[0] = node2;
}

void	sab(t_stack **a, t_stack **b, int print)
{
	if (!a || stack_len(*a) < 2 || !b || stack_len(*b) < 2)
		return ;
	swap(a);
	swap(b);
	if (print)
		write (1, "ss\n", 3);
}

void	sa(t_stack **a, int print)
{
	swap(a);
	if (print)
		write (1, "sa\n", 3);
}

void	sb(t_stack **b, int print)
{
	swap(b);
	if (print)
		write (1, "sb\n", 3);
}
