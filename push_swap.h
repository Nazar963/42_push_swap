/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:55:13 by naal-jen          #+#    #+#             */
/*   Updated: 2023/02/23 09:57:01 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "42_libft/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>

//--------------- create_list.c ----------------
void	ft_create_list(char **av, t_list **stack_a);
void    ft_create_lists(char **av, t_list **stack_a);

//--------------- actions.c --------------------
void	ft_push_b(t_list **stack_a, t_list **stack_b);
void	ft_push_a(t_list **stack_a, t_list **stack_b);
void	ft_swap_a(t_list **stack_a);
void	ft_swap_b(t_list **stack_b);
void	ft_rotate_a(t_list **stack_a);
void	ft_rotate_b(t_list **stack_b);
void	ft_reverse_rotate_a(t_list **stack_a);

bool	ft_check_duplicates(t_list *list);



#endif