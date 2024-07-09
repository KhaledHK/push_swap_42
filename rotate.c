/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khkhaled <khkhaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:15:33 by khaled            #+#    #+#             */
/*   Updated: 2024/07/02 12:22:32 by khkhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **s)
{
	if (!s || stack_len(s[0]) < 2)
		return ;
	add_last(s, find_first(s));
	remove_first(s);
}

void	ra(t_stack **a, int print)
{
	rotate (a);
	if (print == 1 )
	{
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack **b, int print)
{
	rotate (b);
	if (print)
	{
		write(1, "rb\n", 3);
	}
}

void	rab(t_stack **a, t_stack **b, int print)
{
	rotate (a);
	rotate (b);
	if (print)
	{
		write(1, "rr\n", 3);
	}
}
