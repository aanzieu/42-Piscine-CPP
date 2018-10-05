/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 08:30:34 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/05 15:31:17 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

//CONSTRUCTOR
//------------------------
// Init Construtor
ScavTrap::ScavTrap(void)
{
    srand(time(0));
    ClapTrap::set_Stats("* SC4V-TRAP *", 1, 100, 100, 50, 50, 20, 15, 3);
    std::cout << "* SC4V-TRAP * Default Constructor Called! <" << ClapTrap::yellow << this->_Name << ClapTrap::reset << ".ScavTrap> : I need a briefing." << std::endl;
    return;
}
// Constructor with name paramettre
ScavTrap::ScavTrap(std::string name)
{

    srand(time(0));
    ClapTrap::set_Stats(name, 1, 100, 100, 50, 50, 20, 15, 3);
    std::cout << "* SC4V-TRAP * Parameter Constructor Called! <" << ClapTrap::yellow << this->_Name << ClapTrap::reset << ".ScavTrap> : What's the situation?" << std::endl;
    return;
}

// Copy Constructor
ScavTrap::ScavTrap(ScavTrap const & src)
{
    srand(time(0));
    std::cout << "* SC4V-TRAP * Copy constructor called! Dismissed!" << std::endl;
    std::cout << "<" << ClapTrap::yellow << this->_Name << ClapTrap::reset << ".ScavTrap> : What are you waiting for? Get going." << std::endl;
    *this = src;
    return;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "* SC4V-TRAP * Destructor Called: <" << ClapTrap::yellow << this->_Name << ClapTrap::reset << ".ScavTrap> Why are we killing me again?" << std::endl;
    return;
}

ScavTrap & ScavTrap::operator=( ScavTrap const & rhs )
{
    ClapTrap::operator=(rhs);
    std::cout << "* SC4V-TRAP * Assigning Operator = Called : <" << ClapTrap::yellow << this->_Name << ClapTrap::reset << ".ScavTrap> We are Same We Are Same !!! Like it like it !" << std::endl
              << std::endl;
    return (*this);
}


void	ScavTrap::challengeNewcomer(std::string const & target)
{
	int i = rand();
	std::cout << "<" << ClapTrap::yellow << this->_Name << ClapTrap::reset << ">" << " challenges the newcomer <" << ClapTrap::green << target << ClapTrap::reset << "> : ";
    switch ( i % 5 ) {
    case 0 :     
        std::cout << "You versus me! Me versus you! Either way!"
        << std::endl << std::endl;
        break;
    case 1 :     
        std::cout << "I will prove to you my robotic superiority!"
        << std::endl << std::endl;
        break;
    case 2 :
        std::cout << "Dance battle! Or, you know... regular battle."
        << std::endl << std::endl;
        break;
    case 3 :
        std::cout << "Man versus machine! Very tiny streamlined machine!"
        << std::endl << std::endl;
        break;
    case 4 :
        std::cout << "Care to have a friendly duel?"
        << std::endl << std::endl;
        break;
    default:  
        std::cout << "Sorry no idea Challenge today !"
        << std::endl << std::endl;
        break;
    }
}