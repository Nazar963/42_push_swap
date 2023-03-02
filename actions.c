/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:47:38 by naal-jen          #+#    #+#             */
/*   Updated: 2023/03/02 09:50:18 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_a;
	t_list	*new_node;
	int		*temp_val;

	temp_val = (int *)malloc(sizeof(*temp_val));
	if (!*stack_a)
		return ;
	temp_a = *stack_a;
	temp_val = (int *)(temp_a->content);
	*stack_a = temp_a->next;
	new_node = ft_lstnew(temp_val);
	if (!new_node)
		return ;
	if (!*stack_b)
		ft_lstadd_back(stack_b, new_node);
	else
		ft_lstadd_front(stack_b, new_node);
	ft_putstr_fd("pb\n", 1);
	free(temp_a);
}

// void	ft_push_b(t_list **stack_a, t_list **stack_b)
// {
// 	t_list	*temp_a;
// 	if (!stack_a || !(*stack_a))
// 		return ;
// 	temp_a = *stack_a;
// 	if (!*stack_b)
// 		ft_lstadd_back(stack_b, ft_lstnew((int *)(*stack_a)->content));
// 	else
// 		ft_lstadd_front(stack_b, ft_lstnew((int *)(*stack_a)->content));
// 	*stack_a = (*stack_a)->next;
// 	free(temp_a);
// 	ft_putstr_fd("pb\n", 1);
// }

// void	ft_push_b(t_list **stack_a, t_list **stack_b)
// {
// 	t_list	*temp_a;
// 	if (!stack_a || !(*stack_a))
// 		return ;
// 	temp_a = (*stack_a)->next;
// 	if (!*stack_b)
// 		ft_lstadd_back(stack_b, *stack_a);
// 	else
// 		ft_lstadd_front(stack_b, *stack_a);
// 	*stack_a = temp_a;
// 	ft_putstr_fd("pb\n", 1);
// }

void	ft_push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_b;
	t_list	*new_node;
	int		*temp_val;

	temp_val = (int *)malloc(sizeof(*temp_val));
	if (!*stack_b)
		return ;
	temp_b = *stack_b;
	temp_val = (int *)(temp_b->content);
	*stack_b = temp_b->next;
	new_node = ft_lstnew(temp_val);
	if (!new_node)
		return ;
	if (!*stack_a)
		ft_lstadd_back(stack_a, new_node);
	else
		ft_lstadd_front(stack_a, new_node);
	ft_putstr_fd("pa\n", 1);
	// ft_lstclear(&temp_b, &free);
	// ft_lstclear(&new_node, &free);
	// free(temp_val);
}

// void	ft_push_a(t_list **stack_a, t_list **stack_b)
// {
// 	// t_list	*temp_b;

// 	if (!*stack_b || !stack_b)
// 		return ;
// 	// temp_b = *stack_b;
// 	if (!*stack_a)
// 		ft_lstadd_back(stack_a, ft_lstnew((int *)(*stack_b)->content));
// 	else
// 		ft_lstadd_front(stack_a, ft_lstnew((int *)(*stack_b)->content));
// 	*stack_b = (*stack_b)->next;
// 	// free(temp_b);
// 	ft_putstr_fd("pa\n", 1);
// }

void	ft_swap_a(t_list **stack_a)
{
	t_list	*temp_a;
	t_list	*next_node;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	temp_a = *stack_a; // copy the linked list
	next_node = (*stack_a)->next; // save the next node in next_node
	*stack_a = (*stack_a)->next->next; // link the first with the third
	ft_lstadd_front(stack_a, temp_a);
	ft_lstadd_front(stack_a, next_node);
	ft_putstr_fd("sa\n", 1);
	// ft_lstclear(&temp_a, &free);
	// ft_lstclear(&next_node, &free);
}

void	ft_swap_b(t_list **stack_b)
{
	t_list	*temp_b;
	t_list	*next_node;

	if (ft_lstsize(*stack_b) < 2)
		return ;
	temp_b = *stack_b; // copy the linked list
	next_node = (*stack_b)->next; // save the next node in next_node
	*stack_b = (*stack_b)->next->next; // link the first with the third
	ft_lstadd_front(stack_b, temp_b);
	ft_lstadd_front(stack_b, next_node);
	ft_putstr_fd("sb\n", 1);
	// ft_lstclear(&temp_b, &free);
	// ft_lstclear(&next_node, &free);
}

void	ft_rotate_a(t_list **stack_a)
{
	t_list	*first_elem;

	first_elem = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_back(stack_a, first_elem);
	first_elem->next = NULL;
	ft_putstr_fd("ra\n", 1);
	// ft_lstclear(&first_elem, &free);
}

void	ft_rotate_b(t_list **stack_b)
{
	t_list	*first_elem;

	first_elem = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_lstadd_back(stack_b, first_elem);
	first_elem->next = NULL;
	ft_putstr_fd("rb\n", 1);
	// ft_lstclear(&first_elem, &free);
}

void	ft_reverse_rotate_a(t_list **stack_a)
{
	int		size;
	t_list	*temp_a;
	t_list	*last_node;
	int		*value;
	
	value = (int *)malloc(sizeof(int));
	if (!value)
		return ;
	size = ft_lstsize(*stack_a);
	temp_a = *stack_a;
	while (size - 1 > 0)
	{
		temp_a = temp_a->next;
		size--;
	}
	value = (int *)temp_a->content;
	temp_a = NULL;
	temp_a = *stack_a;
	size = 0;
	size = ft_lstsize(*stack_a);
	while (size - 2 > 0)
	{
		temp_a = temp_a->next;
		size--;
	}
	// printf("value%d\n", *(int *)temp_a->content);
	temp_a->next = NULL;
	last_node = ft_lstnew(value);
	ft_lstadd_front(stack_a, last_node);
	ft_putstr_fd("rra\n", 1);
	// ft_lstclear(&temp_a, &free);
	// ft_lstclear(&last_node, &free);
	// free(value);
	// free(last_node);
	// free(temp_a);
}

// void	ft_reverse_rotate_a(t_list **stack_a)
// {
// 	t_list *temp;
// 	t_list	*last_node;
// 	int		size;

// 	size = ft_lstsize(*stack_a);
// 	temp = *stack_a;
// 	while (size - 2 > 0)
// 	{
// 		temp = temp->next;
// 		size--;
// 	}
// 	last_node = temp->next;
// 	temp->next = NULL;
// 	ft_lstadd_front(stack_a, last_node);
// 	ft_putstr_fd("rra\n", 1);
// }

void	ft_reverse_rotate_b(t_list **stack_b)
{
	int		size;
	t_list	*temp_b;
	t_list	*last_node;
	int		*value;
	
	value = (int *)malloc(sizeof(int));
	if (!value)
		return ;
	size = ft_lstsize(*stack_b);
	temp_b = *stack_b;
	while (size - 1 > 0)
	{
		temp_b = temp_b->next;
		size--;
	}
	value = (int *)temp_b->content;
	temp_b = NULL;
	temp_b = *stack_b;
	size = 0;
	size = ft_lstsize(*stack_b);
	while (size - 2 > 0)
	{
		temp_b = temp_b->next;
		size--;
	}
	// printf("value%d\n", *(int *)temp_b->content);
	temp_b->next = NULL;
	last_node = ft_lstnew(value);
	ft_lstadd_front(stack_b, last_node);
	ft_putstr_fd("rrb\n", 1);
	// ft_lstclear(&temp_b, &free);
	// ft_lstclear(&last_node, &free);
	// free(value);
}