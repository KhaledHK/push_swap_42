/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaled <khaled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:30:53 by khaled            #+#    #+#             */
/*   Updated: 2024/06/30 23:21:04 by khaled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(t_stack **s)
{
	if (!s || stack_len(s[0]) < 2)
		return ;
	add_first(s, find_last_int(*s));
	remove_last(s);
}

void	rra(t_stack **a, int print)
{
	rrotate (a);
	if (print)
	{
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack **b, int print)
{
	rrotate (b);
	if (print)
	{
		write(1, "rrb\n", 4);
	}
}

void	rrab(t_stack **a, t_stack **b, int print)
{
	rrotate (a);
	rrotate (b);
	if (print)
	{
		write(1, "rrr\n", 4);
	}
}
