# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 19:03:52 by kevin             #+#    #+#              #
#    Updated: 2025/03/29 17:05:21 by kbrauer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = identify

FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Base.cpp

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