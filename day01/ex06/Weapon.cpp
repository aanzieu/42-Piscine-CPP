/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 15:34:34 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/03 16:53:21 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Weapon.hpp"


Weapon::Weapon(std::string input) : _typeOfWeapon(input)
{
    if(!input.empty())
    {
        std::cout << "Weapon Set is a " << this->_typeOfWeapon << std::endl;
    }
	return;
}

Weapon::Weapon(void){ return; }
Weapon::~Weapon(void) { return; }

std::string const & Weapon::getType(){
    return this->_typeOfWeapon;
}

void    Weapon::setType(std::string input) {
    if (!input.empty()){
        this->_typeOfWeapon = input;
        std::cout << "New weapon Set, now this is a " << this->_typeOfWeapon << std::endl;
    }
}