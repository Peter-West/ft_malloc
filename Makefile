#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppellegr <ppellegr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/04 15:45:48 by ppellegr          #+#    #+#              #
#    Updated: 2015/11/04 15:46:04 by ppellegr         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME				:= aaaa
SRCS				:= main.c ft_malloc.c
PATH_OBJ			:= objs
PATH_SRC			:= srcs
PATH_INC			:= incs
CXX					:= clang
CXXFLAGS			:= -Wall -Wextra -Werror
DEBUG				:= -g
OBJECTS				:= $(patsubst %.c, $(PATH_OBJ)/%.o, $(SRCS))
INCLUDES			:= -I./$(PATH_INC)
LIBFT				:= libft/


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) -o $@ $(OBJECTS) $(DEBUG) $(CXXFLAGS) 

$(PATH_OBJ)/%.o: $(addprefix $(PATH_SRC)/,%.c)
	@mkdir -p $(PATH_OBJ)
	$(CXX) -c -o $@ $(CXXFLAGS) $^ $(DEBUG) $(INCLUDES)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)