# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 22:09:18 by caalbert          #+#    #+#              #
#    Updated: 2024/02/03 22:47:22 by caalbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = claptrap

SRCS = main.cpp ClapTrap.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = ClapTrap.hpp

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
