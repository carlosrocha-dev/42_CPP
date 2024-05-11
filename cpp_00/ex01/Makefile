# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 15:09:45 by caalbert          #+#    #+#              #
#    Updated: 2024/01/23 17:30:03 by caalbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= phonebook
CC		= c++ -std=c++98
CFLAGS	= -Wall -Wextra -Werror
SOURCES	= main.cpp Contact.cpp PhoneBook.cpp
OBJ		= $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
OBJ_DIR	= objs
RM		= rm -rf

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
