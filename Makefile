# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/31 09:32:22 by eteixeir          #+#    #+#              #
#    Updated: 2026/03/31 09:49:20 by eteixeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philosophers

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRC		= main.c philo.c utils.c
OBJ		= $(SRC:.o=.c)

all: 
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(SRC) philo.h
	$(CC) $(CFLAGS) philo.h -c $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f -d $(NAME)

re: fclean all