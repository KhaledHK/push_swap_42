/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khkhaled <khkhaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:06:48 by khaled            #+#    #+#             */
/*   Updated: 2024/07/02 12:27:11 by khkhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
	int				index;
	int				target;
	int				cost;
	int				median_top;
}	t_stack;

char			**split(char *s);
int				word_count(char *str);

void			put_error(void);
void			free_stack(t_stack **s);
void			free_stack_exit(t_stack **s);

int				check_is_not_number(char *str_n);
long			ft_atol(char *s);
void			init_stack_a(t_stack **a, char **argv);

t_stack			*find_last(t_stack *stack);
void			add_last(t_stack **stack, int n);
int				exist_duplicate(t_stack *a, int n);
int				stack_len_print(t_stack *stack);
int				stack_len(t_stack *stack);
void			add_first(t_stack **stack, int n);
void			remove_first(t_stack **stack);
int				find_first(t_stack **stack);
int				find_last_int(t_stack *stack);
void			remove_last(t_stack **stack);
int				is_sorted(t_stack *a);
int				find_max(t_stack *stack);
t_stack			*find_nb(t_stack *stack, int nb);
t_stack			*find_min_cost(t_stack *stack);
int				find_min(t_stack *stack);

void			swap(t_stack **stack);
void			sab(t_stack **a, t_stack **b, int print);
void			sa(t_stack **a, int print);
void			sb(t_stack **b, int print);

void			pa(t_stack **a, t_stack **b, int print);
void			pb(t_stack **a, t_stack **b, int print);

void			ra(t_stack **a, int print);
void			rb(t_stack **b, int print);
void			rab(t_stack **a, t_stack **b, int print);

void			rra(t_stack **a, int print);
void			rrb(t_stack **b, int print);
void			rrab(t_stack **a, t_stack **b, int print);

void			sort_small(t_stack **s);
void			sort(t_stack **a, t_stack **b);
void			set_index_median(t_stack *s);
void			set_target_min(t_stack *a, t_stack *b);
void			cost_calculator(t_stack *a, t_stack *b);
void			push_for_a(t_stack **a, t_stack **b);
void			push_to_top(t_stack **a, t_stack **b, int t_a, int t_b);
void			push_to_button(t_stack **a, t_stack **b, int t_a, int t_b);

void			set_target_max(t_stack *a, t_stack *b);
void			push_for_b(t_stack **a, t_stack **b);
void			min_to_top(t_stack **a);

void			push_a_to_top_x(t_stack **a, int nb, int test);
void			push_b_to_top_x(t_stack **b, int nb, int test);

int				max(int n, int m);
int				min_cost(int l_a, int l_b, int i_a, int i_b);

//get next ligne
size_t			ft_strlen(char *str);
char			*get_next_line(int fd);
char			*ft_readed_line(char *src);
char			*ft_strchr(char *s, int c);
char			*ft_move_start(char *start);
char			*ft_strjoin(char *start, char *buff);
char			*ft_join(char *dest, char *s1, char *s2);

int				ft_strcmp(char *s1, char *s2);

#endif