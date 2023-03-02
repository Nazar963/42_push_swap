/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:43:15 by naal-jen          #+#    #+#             */
/*   Updated: 2023/02/28 13:10:06 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_one(char **av)
{
	char	**str;
	int		i;
	int		j;

	str = ft_split(av[1], ' ');
	i = 0;
	j = 0;
	if (ft_strlen(str[i]) == 0 || (str[i][j] == '-' && str[i][j + 1] == 0))
	{
		ft_free(str);
		return (0);
	}
	while (str[i])
	{
		if (str[i][j] == '-')
			j++;
		if (str[i][j] == '\0')
			return (0);
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
			{
				ft_free(str);
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	ft_free(str);
	return (1);
}

static int	ft_check_two(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (ft_strlen(av[i]) == 0 || (av[i][j] == '-' && av[i][j + 1] == 0))
		return (0);
	while (av[i])
	{
		if (av[i][j] == '-')
			j++;
		if (av[i][j] == '\0')
			return (0);
		while (av[i][j])
		{

			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	ft_check_if_num(int ac, char **av)
{
	int	res;

	res = 1;
	if (ac == 2)
		res = ft_check_one(av);
	else if (ac > 2)
		res = ft_check_two(av);
	return (res);
}

static int	ft_check_sorted_one(char **av)
{
	int		i;
	int		size;
	char	**str;

	i = 0;
	str = ft_split(av[1], ' ');
	while (str[i])
		i++;
	size = i;
	i = 0;
	while (i < size - 1)
	{
		if (ft_atoi(str[i]) > ft_atoi(str[i + 1]))
		{
			ft_free(str);
			return (1);
		}
		i++;
	}
	ft_free(str);
	return (0);
}

static int	ft_check_sorted_two(int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac - 1)
	{
		if (ft_atoi(av[i]) > ft_atoi(av[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_if_sorted(int ac, char **av)
{
	int	res;

	res = 1;
	if (ac == 2)
		res = ft_check_sorted_one(av);
	else if (ac > 2)
		res = ft_check_sorted_two(ac, av);
	return (res);
}