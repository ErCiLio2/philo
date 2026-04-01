# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/31 09:32:22 by eteixeir          #+#    #+#              #
#    Updated: 2026/03/31 11:00:30 by eteixeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philosophers

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRC		= main.c philo.c utils.c
OBJ		= $(SRC:.c=.o)

all: $(NAME) 

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f -d $(NAME)

re: fclean all

.PHONY: all clean fclean re