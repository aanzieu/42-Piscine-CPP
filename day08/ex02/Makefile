# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/12 17:18:37 by aanzieu           #+#    #+#              #
#    Updated: 2018/10/12 17:18:52 by aanzieu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= mutate

SRC		= main.cpp mutantstack.cpp

CFLAG	= -Wall -Wextra -Werror

.SILENT:

all: $(NAME)

$(NAME):
	clang++ $(CFLAG) $(SRC) -I . -o $(NAME)
	printf '\033[32m[✔] %s\n\033[0m' "Created mutate"

clean:
	/bin/rm -f *.o
	printf '\033[31m[✔] %s\n\033[0m' "Cleaned mutate"

fclean: clean
	/bin/rm -f $(NAME)
	printf '\033[31m[✔] %s\n\033[0m' "Fcleaned mutate"

re: fclean all

.PHONY: clean fclean re all test
