/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaled <khaled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:59:37 by khkhaled          #+#    #+#             */
/*   Updated: 2024/07/01 19:24:42 by khaled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **s1, t_stack **s2)
{
	if (!s1 || s1[0] == NULL)
	{
		return ;
	}
	add_first(s2, find_first(s1));
	remove_first(s1);
}

void	pa(t_stack **a, t_stack **b, int print)
{
	push (a, b);
	if (print)
		write (1, "pb\n", 3);
}

void	pb(t_stack **a, t_stack **b, int print)
{
	push (b, a);
	if (print)
		write (1, "pa\n", 3);
}
