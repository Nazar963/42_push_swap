/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:55:13 by naal-jen          #+#    #+#             */
/*   Updated: 2023/03/02 08:50:28 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "42_libft/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

# define INT_MAX 2147483647
# define HASH_TABLE_SIZE 1000000

typedef struct s_loco
{
	long int	*value;
}	t_loco;

//--------------- create_list.c ----------------
void	ft_create_list(char **av, t_list **stack_a);
void	ft_create_lists(int ac, char **av, t_list **stack_a, t_loco *loco);

//--------------- actions.c --------------------
void	ft_push_b(t_list **stack_a, t_list **stack_b);
void	ft_push_a(t_list **stack_a, t_list **stack_b);
void	ft_swap_a(t_list **stack_a);
void	ft_swap_b(t_list **stack_b);
void	ft_rotate_a(t_list **stack_a);
void	ft_rotate_b(t_list **stack_b);
void	ft_reverse_rotate_a(t_list **stack_a);
void	ft_reverse_rotate_b(t_list **stack_b);

//--------------- checks.c ---------------------
int	ft_check_if_num(int ac, char **av);
// int	ft_check_if_sorted(t_list **stack_a);
int	ft_check_if_sorted(int ac, char **av);

//--------------- sort_5.c -------------
// void	ft_insertion_sort(t_list **stack_a);
void sort_5_numbers(t_list **stack_a, t_list **stack_b);

//--------------- radix_sort.c -----------------
void radix_sort(t_list **stack_a, t_list **stack_b);


//--------------- ft_free.c -------------------
void	ft_free(char **str);




#endif