# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: locharve <locharve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 10:00:46 by locharve          #+#    #+#              #
#    Updated: 2024/11/15 10:01:33 by locharve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME ?= bureaucrat

SRC ?= main.cpp Bureaucrat.cpp

SRC_DIR = ./src
OBJ_DIR = ./obj

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

HEADER = -I ./header

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@test -d $(OBJ_DIR) || mkdir $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@ $(HEADER)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) $(HEADER) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

c: all clean

re: clean all

.PHONY: all, clean, fclean, c, re