# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 14:00:35 by ilasrarf          #+#    #+#              #
#    Updated: 2023/02/08 16:17:31 by ilasrarf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC1 = server.c
SRC2 = client.c
SRC1_B = server_bonus.c
SRC2_B = client_bonus.c

O_SRC1 = $(SRC1:%.c=%.o)
O_SRC2 = $(SRC2:%.c=%.o)
O_SRC1_B = $(SRC1_B:%.c=%.o)
O_SRC2_B = $(SRC2_B:%.c=%.o)

NAME = minitalk
RM = rm -f
CC = cc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c minitalk.h
	@$(CC) $(FLAGS) -c $<

$(NAME): $(O_SRC1) $(O_SRC2) minitalk.h
	@$(CC) $(FLAGS) $(O_SRC1) -o server
	@$(CC) $(FLAGS) $(O_SRC2) -o client

bonus: $(O_SRC1_B) $(O_SRC2_B) minitalk.h
	@$(CC) $(FLAGS) $(O_SRC1_B) -o server_bonus
	@$(CC) $(FLAGS) $(O_SRC2_B) -o client_bonus
	

clean:
	$(RM) server.o client.o 

fclean: clean
	$(RM) server client

re: fclean all

.PHONY: all fclean re clean bonus $(NAME)