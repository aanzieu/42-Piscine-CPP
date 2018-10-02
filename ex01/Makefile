# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 09:34:15 by aanzieu           #+#    #+#              #
#    Updated: 2018/10/02 14:28:17 by aanzieu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

GPP = g++ -Wall -Wextra -Werror

C_CLASS = Class
C_DIR = Srcs

C_FILES = $(addprefix $(C_DIR)/, \
			main.cpp \
			\
			$(C_CLASS)/Class.Contacts.cpp \
			$(C_CLASS)/Class.Tools.cpp \
			\
			) \

O_DIR = objs
O_FILES = $(C_FILES:$(C_DIR)/%.c=$(O_DIR)/%.o)

# H_DIR = includes
# INCL = -I$(H_DIR)

all : $(NAME)

$(NAME) : $(O_FILES)
	@$(GPP) $(O_FILES) -o $@
	@printf "%-45s\033[1;31m%s\n\033[0m" "-- EXEC ------------------------" "OK"
	@printf  "%-45s\033[1;32m%s\033[0m\n" "Make $@" "OK"



clean :
	@rm -rf $(O_DIR)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : clean all fclean re
