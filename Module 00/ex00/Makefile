# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/15 22:30:05 by lcouto            #+#    #+#              #
#    Updated: 2021/10/15 22:36:34 by lcouto           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRC = megaphone.cpp

OBJS = megaphone.o

CC	= clang++

RM	= rm -rf

CFLAGS	= -Wall -Wextra -Werror -g  -std=c++98

ifeq ($(SANITIZE_A),true)
	CFLAGS += -fsanitize=address -fno-omit-frame-pointer
endif

ifeq ($(SANITIZE_L),true)
	CFLAGS += -fsanitize=leak -fno-omit-frame-pointer
endif

$(NAME): $(OBJS)
		@-$(CC) $(CFLAGS) $(OBJS) $(HEADER) -o $(NAME)
		@echo "created $(NAME) executable file successfully!"

$(OBJS): $(SRC)
		@$(CC) $(CFLAGS) -c $< -o $@
		@echo "Compiled "$<" successfully!"

all: $(NAME)

clean:
		@$(RM) $(OBJS)

fclean:	clean
		@$(RM) $(NAME)
		@$(RM) $(OBJS)
		@echo "Cleanup completed!"

re:		fclean all

PHONY:	all clean fclean re