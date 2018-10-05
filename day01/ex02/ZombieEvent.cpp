/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 07:57:47 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/03 12:53:38 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void) {
    this->typeEvent = "";
    return;
}

ZombieEvent::~ZombieEvent(void) {

    std::cout << "Zombie events has back to root" << std::endl;
    return;
}

void    ZombieEvent::setZombietype_(std::string type) {
    
    if (!type.empty()){
        this->typeEvent = type;
        // Announce event setZombie
        std::cout << "Zombie type has bn set ! OH MY GOD IT'S a " \
        << this->typeEvent << std::endl;
    } else {
        std::cout << "Please Specify a type" \
        << std::endl;
    }
}

Zombie*     ZombieEvent::newZombie(std::string name) {

    if (!name.empty()){
        Zombie *worldWarZ = new Zombie(name, this->typeEvent);
        return (worldWarZ);
    }
    return (NULL);
}

Zombie*	ZombieEvent::randomChump()
{
    srand(time(0));
	int i = rand();
	std::string name;

    switch ( i % 8 ) {
    case 0:     
        name = "Serpentar";
        break;
    case 1:     
        name = "Cocoon";
        break;
    case 2:    
        name = "Noctilia";
        break;
    case 3:    
       name = "SNCF";
        break;
    case 4:    
        name = "Prince Delu";
        break;
    case 5:    
        name = "Fleigmatik";
        break;
    case 6:    
        name = "CouCourouCou";
        break;
    case 7:    
        name = "Plop";
        break;
    case 8:    
        name = "RainBow";
        break;
    case 9:    
        name = "BowRein";
        break;
    default:  
        name = "Pepito Default";
        break;
    }
	Zombie	*createRandomZombie_Name = this->newZombie(name);
    if(createRandomZombie_Name) {
        return createRandomZombie_Name;
    }
	return (NULL);
}