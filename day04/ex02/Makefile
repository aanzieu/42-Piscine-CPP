# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 10:19:47 by aanzieu           #+#    #+#              #
#    Updated: 2018/10/06 21:12:29 by aanzieu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= day04

SRC		= AssaultTerminator.cpp \
		Squad.cpp \
		TacticalMarine.cpp \
		main.cpp

CFLAG	= -Wall -Wextra -Werror

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(CFLAG) $(SRC) $^ -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Created"

./objects/%.o: ./sources/%.cpp
	mkdir -p objects
	clang++ -c $< -o $@

clean:
	rm -rf objects
	/bin/rm -f *.o
	/bin/rm -rf ./objects/*.o
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Cleaned"

fclean: clean
	/bin/rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fcleaned"

re: fclean all

.PHONY: clean fclean re all test