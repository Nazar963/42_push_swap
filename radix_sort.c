/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 08:58:21 by naal-jen          #+#    #+#             */
/*   Updated: 2023/03/03 18:01:37 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	countbits(int num)
{
	int	count;

	count = 1;
	while (num && count++)
		num >>= 1;
	return (count - 1);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	i;
	int	nb;

	nb = countbits(ft_lstsize(*stack_a) - 1);
	i = -1;
	while (++i < nb)
	{
		size = ft_lstsize(*stack_a) + 1;
		while (--size)
		{
			if (*(int *)((*stack_a)->content) & (1 << i))
				ft_rotate_a(stack_a, 0);
			else
				ft_push_b(stack_a, stack_b);
		}
		size = ft_lstsize(*stack_b) + 1;
		while (--size)
			ft_push_a(stack_a, stack_b);
	}
}
