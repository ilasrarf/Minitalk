# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 14:00:35 by ilasrarf          #+#    #+#              #
#    Updated: 2023/02/09 19:37:14 by ilasrarf         ###   ########.fr        #
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

CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

NAME = minitalk
RM = rm -f
CC = cc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c 
	$(CC) $(FLAGS) -c $<

$(NAME): client server

client:  $(O_SRC2) minitalk.h
	$(CC) $(FLAGS) $(O_SRC2) -o $(CLIENT)

server: $(O_SRC1) minitalk.h
	$(CC) $(FLAGS) $(O_SRC1) -o $(SERVER)

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): $(O_SRC2_B) minitalk.h
	$(CC) $(FLAGS) $(O_SRC2_B) -o $(CLIENT_BONUS)

$(SERVER_BONUS): $(O_SRC1_B) minitalk.h
	$(CC) $(FLAGS) $(O_SRC1_B) -o $(SERVER_BONUS)

clean:
	$(RM) $(O_SRC1) $(O_SRC2)
	$(RM) $(O_SRC1_B) $(O_SRC2_B)

fclean: clean
	$(RM) server client
	$(RM) server_bonus client_bonus

re: fclean all

.PHONY: all fclean re clean bonus $(NAME)