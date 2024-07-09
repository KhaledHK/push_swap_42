/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaled <khaled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:03:03 by khaled            #+#    #+#             */
/*   Updated: 2024/07/01 18:51:16 by khaled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && word_count(argv[1]) < 2) || !argv[1])
		put_error();
	else if (argc == 2)
		argv = split(argv[1]);
	init_stack_a(&a, argv + 1);
	if (!is_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, 1);
		else if (stack_len(a) == 3)
			sort_small(&a);
		else
			sort(&a, &b);
	}
	free_stack(&a);
}

// int main(int argc, char *argv[])
// {
//     t_stack     *a;
//     t_stack     *b;
//     // char **str;
//     a = NULL;
//     b = NULL;
//     if (argc == 1 || (argc == 2 && word_count(argv[1]) < 2) || !argv[1])
//         put_error();
//     else if (argc == 2)
//         argv = split(argv[1]);
//     //   for (int i = 1; argv[i] != NULL; i++) {
//     //     printf("%s\n", argv[i]);
//     // }
//     init_stack_a(&a,argv + 1);
//     // add_first(&a, 24);
//     // swap(&a);
//     // remove_first(&a);
//     // ra(&a,0);
// 	//     sa(&a,0);
//     // ra(&a,0);
//     // ra(&a,0);
//     // rra(&a,0);
//     // pb(&a,&b,0);
//     // add_first(&b,44);
//     //  pa(&a,&b,0);
//     //  sb(&a,1);
//     //  pa(&a,&b,0);
//     //  pa(&a,&b,0);
//     //  pa(&a,&b,0);
//     // rab(&a,&b,0);
//     // remove_last(&a);
//     //  rrab(&a,&b,0); 
//     //  pa(&a,&b,0);
//     //  pb(&a,&b,0);
//  //   
// 	if (!is_sorted(a))
// 	{
// 		if (stack_len(a) == 2)
// 			sa(&a, 1);
// 		else if (stack_len(a) == 3)
// 			sort_small(&a);
// 		else
// 			sort(&a, &b);		
// 	}
//  //
// // t_stack *lst = find_nb(a, 2);
// // lst->target = 50;
// //  lst->cost = -1;
// //  pa(&a,&b,1);
// //  pa(&a,&b,1);
// //  pa(&a,&b,1);
// //  set_index_median(a);
// //  set_index_median(b);
// //  pa(&a,&b,1);
// //  push_to_top(&a, &b, lst);
// // rrab(&a,&b,1);
// // rrab(&a,&b,1);
//     // printf("\n start stack a\n");
//     // stack_len_print(a);
//     // printf("\n end stack a\n");
//     //  printf("\n start stack b\n");
//     // stack_len_print(b);
//     // printf("\n end stack b\n");
//     //  printf("\n is sorted %d\n",is_sorted(a)); 	
//     free_stack(&a);   
//     // while(*str !=NULL)
//     // {
//     //     free(*str);
//     //    (*str)++;
//     // }    
// // 
//     // char **s;
//     // s = ft_split("1 2 3 4"); 
//     // while (*s != NULL)
//     // {
//     //    printf("XXX %s XXXX\n\n", *s);
//     //    s++;
//     // }   
//     // printf("kk %d %s\n\n",argc,argv[0]);
//     // printf(" %d \n",word_count(""));
//     // return 0;
// }