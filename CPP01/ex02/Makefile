# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/12 17:29:53 by kbrauer           #+#    #+#              #
#    Updated: 2024/10/12 17:57:19 by kbrauer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Brain

FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp

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