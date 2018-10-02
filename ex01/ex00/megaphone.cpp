/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 09:11:23 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/01 16:57:16 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int     main(int argc, char **argv){

    if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	} else {
        std::locale loc;
        for (int i = 1; i < argc ; i++){
            std::string str = argv[i];
            for (size_t j=0; j < str.length(); j++)
                std::cout << std::toupper(str[j], loc);
        }
        std::cout << std::endl;
    }
    return 0;
}

// Référence : http://www.cplusplus.com/reference/locale/toupper/