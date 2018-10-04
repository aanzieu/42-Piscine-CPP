/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 07:57:41 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/03 12:50:57 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Create instance with name and type
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

    if(!this->nameOfZombie_.empty() && !this->typeOfZombie_.empty()){
        std::cout \
        << "<" << this->nameOfZombie_ \
        << " ( " << this->typeOfZombie_ << " ) " \
        << ">" << "  Braiiiiiiinnnssss......" \
        << std::endl;
    } else {
        std::cout << "Error from something, did you set a name or type for this Zombies ?" << std::endl;
    }
}