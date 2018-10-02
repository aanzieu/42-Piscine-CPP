# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 09:34:15 by aanzieu           #+#    #+#              #
#    Updated: 2018/10/02 14:30:13 by aanzieu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CPP = clang++ -Wall -Wextra -Werror

C_DIR = .
C_FILES = $(addprefix $(C_DIR)/, \
			megaphone.cpp \
			) \

O_DIR = objs
O_FILES = $(C_FILES:$(C_DIR)/%.c=$(O_DIR)/%.o)


all : $(NAME)

$(NAME) : $(O_FILES)
	$(CPP) $(O_FILES) -o $@
	@printf "%-45s\033[1;31m%s\n\033[0m" "-- EXEC ------------------------" "OK"
	@printf  "%-45s\033[1;32m%s\033[0m\n" "Make $@" "OK"

clean :
	@rm -rf $(O_DIR)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : clean all fclean re
