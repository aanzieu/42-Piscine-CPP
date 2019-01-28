# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/10 08:14:48 by aanzieu           #+#    #+#              #
#    Updated: 2018/10/10 17:35:03 by aanzieu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= convert

SRC		= main.cpp

CFLAG	=  -Wall -Wextra -Werror -g3 -std=c++98

.SILENT:

all: $(NAME)

$(NAME):
	clang++ $(CFLAG) $(SRC) -I . -o $(NAME)
	printf '\033[32m[✔] %s\n\033[0m' "Created"

clean:
	/bin/rm -f *.o
	printf '\033[31m[✔] %s\n\033[0m' "Cleaned"

fclean: clean
	/bin/rm -f $(NAME)
	printf '\033[31m[✔] %s\n\033[0m' "Fcleaned"

re: fclean all

.PHONY: clean fclean re all testÎ