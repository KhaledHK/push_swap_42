/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaled <khaled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:50:19 by khaled            #+#    #+#             */
/*   Updated: 2024/06/30 23:34:12 by khaled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	check_is_not_number(char *str_n)
{
	if (!(*str_n == '+'
			|| *str_n == '-'
			|| (*str_n >= '0' && *str_n <= '9')))
		return (0);
	if ((*str_n == '+'
			|| *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9'))
		return (0);
	if (*str_n == '+' || *str_n == '-')
		str_n = str_n + 1;
	while (*str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (0);
		str_n++;
	}
	return (1);
}

long	ft_atol(char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

void	init_stack_a(t_stack **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (check_is_not_number(argv[i]) == 0)
			free_stack_exit(a);
		n = ft_atol(argv[i]);
		if (n > 2147483647 || n < -2147483648)
			free_stack_exit(a);
		if (exist_duplicate(*a, (int)n))
			free_stack_exit(a);
		add_last(a, (int)n);
		i++;
	}
}
