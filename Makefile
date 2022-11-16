# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 08:54:44 by ubegona           #+#    #+#              #
#    Updated: 2022/11/16 11:36:21 by ubegona          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = $(SRCS:.c=.o)
SRCS = ps_errors.o ps_fill_up.o ps_five_input.o ps_legend_quick_sort.o ps_main.o ps_movement.o ps_split.o ps_three_input.o ps_utils_rules.o ps_utils.o ps_free.o
BOBJS = $(BSRCS:.c=.o)
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
	rm -f $(NAME) $(BOBJS)
re : fclean all

.PHONY: all clean fclean re
