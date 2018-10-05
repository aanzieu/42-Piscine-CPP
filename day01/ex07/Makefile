# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/03 18:22:12 by aanzieu           #+#    #+#              #
#    Updated: 2018/10/03 18:24:25 by aanzieu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= replace

SRC		= main.cpp

CFLAG	= -Wall -Wextra -Werror

.SILENT:

all: $(NAME)

$(NAME):
	@clang++ $(CFLAG) $(SRC) -I . -o $(NAME)
	@printf '\033[32m %s\n\033[0m' "Created replace"

clean:
	@/bin/rm -f *.o
	@printf '\033[31m %s\n\033[0m' "Cleaned replace"

fclean: clean
	@/bin/rm -f $(NAME)
	@printf '\033[31m %s\n\033[0m' "Fcleaned replace"

re: fclean all

.PHONY: clean fclean re all test