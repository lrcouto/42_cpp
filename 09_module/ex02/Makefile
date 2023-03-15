# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/15 22:30:05 by lcouto            #+#    #+#              #
#    Updated: 2023/03/14 22:58:47 by lcouto           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

INCLUDES = -I include

CC	= clang++

RM	= rm -rf

CFLAGS	= -Wall -Wextra -Werror -g -std=c++98

DIR_SRCS	=	src
DIR_BUILD	=	build

SRCS		=	$(DIR_SRCS)/main.cpp \

BUILD		=	$(subst $(DIR_SRCS), $(DIR_BUILD), $(SRCS:.cpp=.o))

ifeq ($(SANITIZE_A),true)
	CFLAGS += -fsanitize=address -fno-omit-frame-pointer
endif

ifeq ($(SANITIZE_L),true)
	CFLAGS += -fsanitize=leak -fno-omit-frame-pointer
endif

$(NAME): $(BUILD)
		@-$(CC) $(CFLAGS) $(BUILD) -o $(NAME)
		@echo "created $(NAME) executable file successfully!"

$(DIR_BUILD)/%.o	:	$(DIR_SRCS)/%.cpp
			@mkdir -p $(DIR_BUILD)
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
			@echo "Compiled "$<" successfully!"

all: $(NAME)

clean:
		@$(RM) $(BUILD)
		@$(RM) -r $(DIR_BUILD)
		@echo "Cleanup completed!"

fclean:	clean
		@$(RM) $(NAME)
		@$(RM) $(BUILD)
		@$(RM) -r $(DIR_BUILD)

re:		fclean all

PHONY:	all clean fclean re
