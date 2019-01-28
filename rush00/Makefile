# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 09:31:52 by nbouchin          #+#    #+#              #
#    Updated: 2018/10/06 20:06:24 by aanzieu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

SRC = main.cpp

SRC_CLASS = 	AEntity.class.cpp \
		Enemy.class.cpp \
		EntityPool.class.cpp \
		User.class.cpp \
		Game.class.cpp \
		Time.class.cpp \
		Missile.class.cpp

OBJ = $(SRC:.cpp=.o)
OBJ_CLASS = $(SRC_CLASS:.cpp=.o)

SRCDIR = srcs/
OBJDIR = objs/
SRCDIR_CLASS = class/
OBJDIR_CLASS = objs_class/

SRCS = $(addprefix $(SRCDIR), $(SRC))
OBJS = $(addprefix $(OBJDIR), $(OBJ))
SRCS_CLASS = $(addprefix $(SRCDIR_CLASS), $(SRC_CLASS))
OBJS_CLASS = $(addprefix $(OBJDIR_CLASS), $(OBJ_CLASS))

LIBS = -lncurses
HEADER = -I includes

CC = g++
FLAG =  -c -Wall -Wextra -Werror -g

.PHONY: all clean fclean re
.SUFFIXES: .c .o

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	@mkdir -p $(OBJDIR)
	@$(CC) $(FLAG) $(HEADER) $< -o $@

$(OBJDIR_CLASS)%.o: $(SRCDIR_CLASS)%.cpp
	@mkdir -p $(OBJDIR_CLASS)
	@$(CC) $(FLAG) $(HEADER) $< -o $@

$(NAME): $(OBJS) $(OBJS_CLASS)
	@$(CC) $(OBJS) $(OBJS_CLASS) $(HEADER) $(LIBS) -o $@

clean:
	@/bin/rm -rf $(OBJDIR)
	@/bin/rm -rf $(OBJDIR_CLASS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
