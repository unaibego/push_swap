# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 08:54:44 by ubegona           #+#    #+#              #
#    Updated: 2022/10/25 11:38:09 by ubegona          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = $(SRCS:.c=.o)
SRCS = $(wildcard *.c)
BOBJS = $(BSRCS:.c=.o)
BSRCS = $(wildcard *bonus.c)
AR = gcc
GCCS = gcc -c -Wall -Werror -Wextra
NAME = push_swap.a

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

bonus : $(OBJS) $(BOBJS)
	$(AR) $(OBJS) $(BOBJS)

rebonus: fclean bonus

.PHONY: all clean fclean re
