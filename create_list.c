/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 09:56:53 by naal-jen          #+#    #+#             */
/*   Updated: 2023/02/20 09:22:13 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_create_list(char **av, t_list **stack_a)
{
	t_list	*temp;
	char	**nums;
	int		*a;
	int		i;

	i = -1;
	nums = ft_split(av[1], ' ');
	while (nums[++i])
	{
		a = (int *)malloc(sizeof(*a));
		if (!a)
			return ;
		*a = ft_atoi(nums[i]);

		temp = ft_lstnew(a);
		ft_lstadd_back(stack_a, temp);
	}
}

void    ft_create_lists(char **av, t_list **stack_a)
{
	t_list *temp;
	int		*a;
	int		i;

	i = 0;
	while (av[++i])
	{
		a = (int *)malloc(sizeof(*a));
		if (!a)
			return ;
		*a = ft_atoi(av[i]);

		temp = ft_lstnew(a);
		ft_lstadd_back(stack_a, temp);
	}
}