/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 09:56:53 by naal-jen          #+#    #+#             */
/*   Updated: 2023/03/02 09:43:09 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	quick_sort(int arr[], int left, int right)
{
	int	i;
	int	j;
	int	temp;
	int	pivot;

	i = left;
	j = right;
	pivot = arr[(left + right) / 2];

	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}
	if (left < j)
		quick_sort(arr, left, j);
	if (i < right)
		quick_sort(arr, i, right);
}

int	binary_search(int a[], int e, int l, int r)
{
	int	mid;

	mid = l + (r - l) / 2;
	if (a[mid] == e )
		return (mid);
	else if (a[mid] > e)
		return (binary_search(a, e, l, mid - 1));
	else
		return (binary_search(a, e, mid + 1, r));
}

void	ft_create_list(char **av, t_list **stack_a)
{
	t_list	*temp;
	char	**nums;
	long int	*a;
	int		i;
	long int		*new_num;
	int		*arr;
	int		size;

	// ft_lstclear(stack_a, &free);
	i = 0;
	size = 0;
	nums = ft_split(av[1], ' ');
	while (nums[i])
		i++;
	size = i;
	arr = ( int *)malloc(sizeof(int) * i);
	new_num = (long int *)malloc(sizeof(long int) * i );
	i = -1;
	while (nums[++i])
	{
		a = (long int *)malloc(sizeof(*a));
		if (!a)
			return ;
		*a = ft_atoi(nums[i]);
		if (*a > (long int)(2147483647) || *a < (long int)(-2147483648))
		{
			free(arr);
			ft_free(nums);
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		arr[i] = *a;
		free(a);
		a = NULL;
	}
	i = 0;
	while (i < size)
	{
		new_num[i] = arr[i];
		i++;
	}
	quick_sort(arr, 0, size - 1);
	i = 0;
	while (i < size)
	{
		new_num[i] = binary_search(arr, new_num[i], 0, size - 1);
		i++;
	}
	i = 0;
	while(i < size)
	{
		a = (long int *)malloc(sizeof(*a));
		if (!a)
			return ;
		*a = new_num[i];
		temp = ft_lstnew(a);
		ft_lstadd_back(stack_a, temp);
		i++;
		// free(a);
	}
	// free(temp);
	free(arr);
	free(new_num);
	ft_free(nums);
}


void	ft_create_lists(int ac, char **av, t_list **stack_a, t_loco *loco)
{
	long int	*a;
	int		i;
	int		*new_num;
	int		arr[ac - 1];
	// t_list	*top;

	i = 0;
	while (av[++i])
	{
		a = (long int *)malloc(sizeof(*a));
		if (!a)
			return ;
		*a = ft_atoi(av[i]);
		if (*a > (long int)(2147483647) || *a < (long int)(-2147483648))
		{
			free(a);
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		arr[i - 1] = *a;
		free(a);
		a = NULL;
	}
	i = 0;
	new_num = (int *)malloc(sizeof(int) * ac - 1);
	if (!new_num)
		return ;
	while (i < ac - 1)
	{
		new_num[i] = arr[i];
		i++;
	}
	quick_sort(arr, 0, ac - 2);
	i = 0;
	while (i < ac - 1)
	{
		new_num[i] = binary_search(arr, new_num[i], 0, ac - 2);
		i++;
	}
	i = -1;
	while(++i < ac - 1)
	{
		loco->value = (long int *)malloc(sizeof(long int));
		if (!loco->value)
			return ;
		*loco->value = new_num[i];
		// ft_lstadd_back(stack_a, ft_lstnew((new_num + i)));
		ft_lstadd_back(stack_a, ft_lstnew(loco->value));
	}
	free(new_num);
	// free(loco);
	// return (*stack_a);
}