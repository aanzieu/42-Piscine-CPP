# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/08 12:30:42 by aanzieu           #+#    #+#              #
#    Updated: 2018/10/09 16:00:36 by aanzieu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ex00

SRC		= 	Bureaucrat.cpp \
			main.cpp \
			Form.cpp \
			ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp \
			PresidentialPardonForm.cpp \
			OfficeBlock.cpp \
			Intern.cpp

CFLAG	= -Wall -Wextra -Werror -g3 -fsanitize=address
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(CFLAG) $(SRC) $^ -o $(NAME)
	printf '\033[32m[✔] %s\n\033[0m' "Created"

./objects/%.o: ./sources/%.cpp
	mkdir -p objects
	clang++ -c $< -o $@

clean:
	rm -rf objects
	/bin/rm -f *.o
	/bin/rm -rf ./objects/*.o
	printf '\033[31m[✔] %s\n\033[0m' "Cleaned"

fclean: clean
	/bin/rm -f $(NAME)
	printf '\033[31m[✔] %s\n\033[0m' "Fcleaned"

re: fclean all

.PHONY: clean fclean re all test