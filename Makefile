# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 14:00:35 by ilasrarf          #+#    #+#              #
#    Updated: 2023/02/01 11:30:23 by ilasrarf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = server.c client.c

O_SRC = $(SRC:%.c=%.o)

AR = ar -rc
PRINTF = ft_printf/libftprintf.a
NAME = minitalk
RM = rm -f
CC = cc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(PRINTF):
	cd ft_printf && make

$(NAME) : $(O_SRC) $(PRINTF)
	$(CC) $(FLAGS) $(PRINTF) server.o -o server
	$(CC) $(FLAGS) $(PRINTF) client.o -o client

%.o: %.c minitalk.h
	$(CC) $(FLAGS) -c $<

clean:
	$(RM) $(O_SRC)
	cd ft_printf && make clean

fclean: clean
	$(RM) $(NAME)
	cd ft_printf && make fclean

re: fclean all

.PHONY: all fclean re clean $(NAME) $(PRINTF)