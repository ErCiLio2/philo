# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/31 09:32:22 by eteixeir          #+#    #+#              #
#    Updated: 2026/04/18 16:25:33 by eteixeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

SRC		= 	src/main.c src/init.c\
			src/parse.c src/time.c\
			src/ft_atoi.c src/cleanup.c\
			src/routine.c src/mutex.c\

OBJ		=	$(SRC:.c=.o)

all: $(NAME) 

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f -d $(NAME)

re: fclean all

.PHONY: all clean fclean re