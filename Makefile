# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 15:24:48 by naal-jen          #+#    #+#              #
#    Updated: 2023/03/03 17:54:01 by naal-jen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = -I./includes
AR = ar cr
# ARF = -rcs
NAME = push_swap.a

SRC = main.c main_helper.c push.c reverse_rotate.c rotate.c swap.c check_if_sorted.c create_list.c create_list_helper.c checks.c radix_sort.c sort_5.c ft_free.c
# OBJ = $(SRC:.c=.o)
OBJ = main.o main_helper.o push.o reverse_rotate.o rotate.o swap.o check_if_sorted.o create_list.o create_list_helper.o checks.o radix_sort.o sort_5.o ft_free.o

all: libft $(NAME) compile

libft:
	cd 42_libft && $(MAKE)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(OBJ): $(SRC)
	$(CC) -g $(CFLAGS) $(INC) -c $(SRC)

compile:
	$(CC) $(OBJ) -L./42_libft -lft -o push_swap

clean:
	rm -f $(OBJ)
	rm -f push_swap
	cd 42_libft && $(MAKE) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all libft compile clean fclean re


# CC = cc
# CFLAGS = -Wall -Wextra -Werror
# INC = -I. # what does this flag do with all its variations
# AR = ar # and this one
# ARF = -rcs # and this one
# NAME = push_swap.a
# # check what does the -Cs do

# MAN = main create_list actions checks radix_sort sort_5
# MANFC = $(addsuffix .c, $(MAN))
# # MANFC = $(addprefix ft_,$(addsuffix .c, $(MAN))) # and this one
# # MANO = $(MANFC:.c=.o)

# # MANFC = main.c actions.c create_list.c
# MANO = main.o actions.o create_list.o checks.o radix_sort.o sort_5.o

# all: libft $(NAME) $(MANO) compile

# libft:
# 	cd 42_libft; \
# 	$(MAKE);
# 	# @make -sC 42_libft;

# $(NAME): $(MANO)
# 	$(AR) $(ARF) $@ $^

# $(MANO): $(MANFC)
# 	@$(CC) -c $(CFLAGS) 42_libft/libft.a $(MANFC) 

# compile:
# 	@$(CC) $(MANO) 42_libft/libft.a -o push_swap

# clean:
# 	@rm -f $(MANO); \
# 	rm push_swap; \
# 	cd 42_libft; \
# 	$(MAKE) fclean;

# fclean: clean
# 	@rm -f $(NAME)

# re: fclean all

# .PHONY: bonus all clean fclean re