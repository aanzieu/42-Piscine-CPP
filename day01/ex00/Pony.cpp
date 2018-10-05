/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 17:08:31 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/02 17:45:47 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Pony.hpp"

Pony::Pony(std::string name, int age, std::string color_hair, std::string stack) : 
    Name(name),
    Age(age),
    Hair(color_hair),
    Onstack(stack) 
    {
        std::cout << "Pony " << this->Name << " leaves ! that beautiful, " \
        << "is born on the farm " << this->Onstack \
        << " *** - - - *** and he has " << this->Age << " old"\
        << std::endl;
        return;
}

Pony::~Pony(void) 
{
	std::cout << "Pony " << this->Name << " DIED " << std::endl;
	return;
}

void    Pony::CreepCrap(void){
    
    std::cout << "Crap Pmy " << this->Name << std::endl;
    std::cout << "   _____,,;;;`;       ;';;;,,_____     "  << std::endl;
    std::cout << ",~(  )  , )~~\\|       |/~~( ,  (  )~; "  << std::endl;
    std::cout << "' / / --`--,             .--'-- \\ \\  "  << std::endl; 
    std::cout << " /  \\    | '             ` |    /  |  "  << std::endl; 
    
    std::cout << " ,your hair is so " << this->Hair << " UhUhUh" << std::endl;
}