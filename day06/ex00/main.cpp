/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 08:19:43 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/10 17:25:23 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
// #include "Convert.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "You enter one value to convert" << std::endl;
        return (0);
    }

    char *s = av[1];
    std::string tmp = av[1];
    std::cout << std::setprecision(1);
    std::cout << "char: ";
    int check = static_cast<int>(std::strtod(s, NULL));
    if (check >= 32 && check <= 126)
        std::cout << "'" << static_cast<char>(check) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;

    int check_int = 0;
    std::cout << "int: ";
    check_int = static_cast<int>(std::strtod(s, NULL));
    if (check_int != INT_MIN)
        std::cout <<check_int << std::endl;
    else {
        std::cout << "impossible" << std::endl;
    }
    
    float check_float = 0.0f;
    std::cout << std::setprecision(8);
    std::cout << "float: ";
    check_float = static_cast<float>(std::strtod(s, NULL));
    if (check_float)// {
        std::cout << check_float << "f" << std::endl;
    else if(check_float == 0) {
        std::cout << "0.0f" << std::endl;
    }
    else {
         std::cout << "impossible" << std::endl;
    }

    double check_double = 0.0;
    std::cout << std::setprecision(10);
    std::cout << "double: ";
    check_double = static_cast<double>(std::strtod(s, NULL));
    if(check_double)
        std::cout << check_double << std::endl;
    else if (!check_double){
        std::cout << "0.0" << std::endl;
    }
    else {
        std::cout << "impossible" << std::endl;
    }
    return (0);
}

