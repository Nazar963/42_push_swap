/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:02:01 by naal-jen          #+#    #+#             */
/*   Updated: 2023/02/23 09:57:03 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool ft_check_duplicates(t_list *list)
{
    bool seen[1000] = { false }; // initialize all values to false
    while (list != NULL)
    {
        int num = *(int *)list->content; // assuming the list contains integers
        if (seen[num])
        {
            return true; // duplicate found
        }
        seen[num] = true; // add to the hash set
        list = list->next;
    }
    return false; // no duplicates found
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 2)
		ft_create_list(av, &stack_a);
	if (ac > 2)
		ft_create_lists(av, &stack_a);
	if (ft_check_duplicates(stack_a) == true)
		exit(EXIT_FAILURE);

	// ft_rotate_a(&stack_a);
	// ft_push_b(&stack_a, &stack_b);
	// ft_push_b(&stack_a, &stack_b);
	// ft_push_b(&stack_a, &stack_b);
	// ft_rotate_b(&stack_b);
	// ft_swap_a(&stack_b);
	// ft_push_a(&stack_a, &stack_b);
	// ft_push_a(&stack_a, &stack_b);
	// ft_swap_a(&stack_a);
	ft_reverse_rotate_a(&stack_a);
	while (stack_a != NULL)
	{
		printf("%d\n", *(int *)stack_a->content);
		stack_a = stack_a->next;
	}
	printf("stack_a\n");
	// looping through the list getting the address and not the content "value" of the node
	while (stack_b != NULL)
	{
		printf("%d\n", *(int *)stack_b->content);
		stack_b = stack_b->next;
	}
	printf("stack_b\n");
	// // int size = ft_lstsize(stack_a);

	// // while (size - 2 > 0)
	// // {
	// // 	printf("%d\n", *(int *)stack_a->content);
	// // 	stack_a = stack_a->next;
	// // 	size--;
	// // }
	// printf("last node: %d\n", *(int *)stack_a->content);
}