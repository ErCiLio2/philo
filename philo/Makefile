# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/31 09:32:22 by eteixeir          #+#    #+#              #
#    Updated: 2026/04/19 16:59:40 by eteixeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

SRC		= 	 ./main.c  ./init.c ./parse.c  ./time.c\
			 ./ft_atoi.c  ./cleanup.c ./routine.c  ./mutex.c\
			 ./actions.c  ./print.c ./monitor.c

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