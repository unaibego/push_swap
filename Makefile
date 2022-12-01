# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 08:54:44 by ubegona           #+#    #+#              #
#    Updated: 2022/11/16 12:55:47 by ubegona          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = $(SRCS:.c=.o)
SRCS = ps_errors.c ps_fill_up.c ps_five_input.c ps_legend_quick_sort.c ps_main.c ps_movement.c ps_split.c ps_three_input.c ps_utils_rules.c ps_utils.c ps_free.c
AR = gcc -o push_swap
GCCS = gcc -c -Wall -Werror -Wextra -g3
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(OBJS)
	
%.o: %.c 
	$(GCCS) $<	
#$< gure leheneng dependentziaren izena da, kasu honetan %.c

clean: 
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re : fclean all

.PHONY: all clean fclean re
