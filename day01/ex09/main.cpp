/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 22:18:20 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/03 23:18:40 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"


bool    is_space(std::string & str){

    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
            if (*it != ' ')
                return false;
    };
    return true;
}
int    error_parse(){
    std::cout << "Choose dest and message not empty" << std::endl <<
        "valid dest are : file, console" << std::endl << 
        "./a.out [destination] [your message] " << std::endl;

    return (0);
}

int	main(int ac, char **av)
{
	Logger 		    logger;
	std::string     dest, message;

	if (ac != 3) {
		return error_parse();
    }
	dest.append(av[1]);
	message.append(av[2]);
	if (dest.compare("file") == 0 || dest.compare("console") == 0)
	{
		if (message.empty() || is_space(message)) {
			std::cout << "Blank message." << std::endl;
			return error_parse();
        }
		std::cout << "dest type is " << dest << std::endl;
		logger.log(dest, message);
	}
	else
	    return error_parse();
}