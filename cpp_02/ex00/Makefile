# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 00:08:57 by caalbert          #+#    #+#              #
#    Updated: 2024/02/02 17:14:53 by caalbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed

SRCS = main.cpp Fixed.cpp
OBJS = $(SRCS:.cpp=.o)

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "Compilation completed."

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully."

clean:
	@rm -f $(OBJS)
	@echo "Cleaned up object files."

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned up compiled binary."

re: fclean all

.PHONY: all clean fclean re
