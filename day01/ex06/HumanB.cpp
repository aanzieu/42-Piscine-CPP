/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 15:34:41 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/03 17:01:20 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string   name) : _name(name) {
    return;
}

HumanB::HumanB(void){ return; }


HumanB::~HumanB(void){ return ;}


// Function
void        HumanB::attack() const{
	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weap)
{
	this->_weapon = &weap;
}


