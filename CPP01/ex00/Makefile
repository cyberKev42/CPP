# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/12 14:56:12 by kbrauer           #+#    #+#              #
#    Updated: 2024/10/12 14:57:41 by kbrauer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Zombie

FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

.c.o:
	c++ $(FLAGS) -c $< -o $(<:.cpp=.o)

$(NAME): $(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re