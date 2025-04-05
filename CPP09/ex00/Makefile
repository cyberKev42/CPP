# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 16:23:10 by kevin             #+#    #+#              #
#    Updated: 2025/04/03 13:24:56 by kbrauer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

FLAGS = -Wall -Wextra -Werror -std=c++98 

SRCS = main.cpp BitcoinExchange.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

.cpp.o:
	c++ $(FLAGS) -c $< -o $(<:.cpp=.o)

$(NAME): $(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re