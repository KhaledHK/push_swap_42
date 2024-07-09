/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaled <khaled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:56:39 by khaled            #+#    #+#             */
/*   Updated: 2024/06/30 23:30:12 by khaled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack **s)
{
	t_stack	*temp;

	if (!s)
		return ;
	while (*s)
	{
		temp = (*s)->next;
		s[0]->nb = 0;
		s[0]->next = NULL;
		free(s[0]);
		*s = temp;
	}
}

void	free_stack_exit(t_stack **s)
{
	free_stack (s);
	put_error();
}
