/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 07:57:41 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/03 14:15:02 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Create instance alone
Zombie::Zombie(void){
    return;
}
// Create instance
Zombie::Zombie(std::string name, std::string type) : 
    nameOfZombie_(name),
    typeOfZombie_(type)
    {
	announce_Zombie_();
    return;
}

// Destroy Instance
Zombie::~Zombie(void) {
	std::cout << this->nameOfZombie_ << " has returned back to root" << std::endl;
    return;
}

// Function Member
void    Zombie::announce_Zombie_(void) const{

    std::cout \
    << "<" << this->nameOfZombie_ \
    << " ( " << this->typeOfZombie_ << " ) " \
    << ">" << "  Braiiiiiiinnnssss......" \
    << std::endl;
}