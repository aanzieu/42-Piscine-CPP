/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:29:14 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/06 11:11:05 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void) : Enemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads !" << std::endl;
    return;
}

SuperMutant::SuperMutant(SuperMutant const & src ) : Enemy(src)
{
    *this = src;
    std::cout << "Gaaah. Me want smash heads !" << std::endl;
    return;
}

SuperMutant::~SuperMutant(void)
{
    std::cout << "Aaargh ..." << std::endl;
    return;
}

SuperMutant &SuperMutant::operator=(SuperMutant const &r)
{
    Enemy::operator=(r);
    return (*this);
}

void SuperMutant::takeDamage(int amount)
{
    int i = 0;

    if (amount < 3)
        return;
    else if (amount > (this->getHP() + 3))
        i = this->getHP() + 3;
    else
        i = amount;
    this->setHP(this->getHP() - i + 3);
    if (this->getHP() < 0)
        this->setHP(0);
    return;
}