# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/31 09:32:22 by eteixeir          #+#    #+#              #
#    Updated: 2026/04/07 23:17:27 by eteixeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philosophers

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRC		= 	src/main.c src/mutex.c src/philo.c\
			src/utils/utils.c src/utils/time.c src/utils/clear_data.c
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