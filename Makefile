# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 14:00:35 by ilasrarf          #+#    #+#              #
#    Updated: 2023/02/06 15:20:14 by ilasrarf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = manda/server.c manda/client.c

O_SRC = $(SRC:%.c=%.o)

AR = ar -rc
NAME = minitalk
RM = rm -f
CC = cc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(O_SRC) minitalk.h
	$(CC) $(FLAGS) server.o -o server
	$(CC) $(FLAGS) client.o -o client

%.o: %.c minitalk.h
	$(CC) $(FLAGS) -c $<

clean:
	$(RM) server.o client.o 

fclean: clean
	$(RM) server client

re: fclean all

.PHONY: all fclean re clean $(NAME)