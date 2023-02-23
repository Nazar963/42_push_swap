# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 15:24:48 by naal-jen          #+#    #+#              #
#    Updated: 2023/02/21 15:56:21 by naal-jen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -I. # what does this flag do with all its variations
AR = ar # and this one
ARF = -rcs # and this one
NAME = push_swap.a
# check what does the -Cs do

MAN = main create_list actions
# MANFC = $(addsuffix .c, $(MAN))
# # MANFC = $(addprefix ft_,$(addsuffix .c, $(MAN))) # and this one
# MANO = $(MANFC:.c=.o)

MANFC = main.c actions.c create_list.c
MANO = main.o actions.o create_list.o

all: libft $(NAME) $(MANO) compile

libft:
	cd 42_libft; \
	$(MAKE);
	# @make -sC 42_libft;

$(NAME): $(MANO)
	$(AR) $(ARF) $@ $^

$(MANO): $(MANFC)
	@$(CC) -c $(CFLAGS) $(MANFC)

compile:
	@$(CC) $(MANO) 42_libft/libft.a -o push_swap

clean:
	@rm -f $(MANO); \
	cd 42_libt; \
	$(MAKE) fclean;

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re