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

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME				:= libft_malloc_$(HOSTTYPE).so
SRCS				:= ft_malloc.c
PATH_OBJ			:= objs
PATH_SRC			:= srcs
PATH_INC			:= incs
CXX					:= clang
CXXFLAGS			:= -Wall -Wextra -Werror
DEBUG				:= -g
OBJECTS				:= $(patsubst %.c, $(PATH_OBJ)/%.o, $(SRCS))
INCLUDES			:= -I./$(PATH_INC)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) -o $@ $(OBJECTS) $(DEBUG) $(CXXFLAGS) -shared -fpic
	rm -f libft_malloc.so
	ln -s $(NAME) libft_malloc.so

$(PATH_OBJ)/%.o: $(addprefix $(PATH_SRC)/,%.c)
	@mkdir -p $(PATH_OBJ)
	$(CXX) -c -o $@ $(CXXFLAGS) $^ $(DEBUG) $(INCLUDES)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)
	rm -f libft_malloc.so

re: fclean $(NAME)