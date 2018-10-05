/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:22:23 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/05 17:01:07 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "SuperTrap.hpp"
#include "ClapTrap.hpp"

SuperTrap::SuperTrap(void) : ClapTrap(), FragTrap(), NinjaTrap()
{
	srand(time(0));
	this->set_Stats(" * SUPER-TRAP *", 1, 100, 100, 120, 120, 60, 20, 5);
	std::cout << "* SUPER-TRAP * Default Constructor Called: < " << this->_Name << " > Im Who I Am ! " << std::endl;
	return;
}

SuperTrap::SuperTrap(std::string name) : ClapTrap(name), FragTrap(name), NinjaTrap(name)
{
	srand(time(0));
	this->set_Stats(name, 1, 100, 100, 120, 120, 60, 20, 5);
	std::cout << "SUPER-TRAP Parameter Constructor Called: < " 
              << this->_Name << " > Im Who I Am!" << std::endl;
	return;
}

SuperTrap::SuperTrap(SuperTrap const & src) : ClapTrap(src), FragTrap(src), NinjaTrap(src)
{
	srand(time(0));
	*this = src;
	std::cout << "SUPER-TRAP Copy Constructor Called : < " << this->_Name << " > Im Who I Am" << std::endl;
	return;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << "SUPER-TRAP Destructor Called: < " << this->_Name << " > Im Who I Am" << std::endl;
	return;
}

SuperTrap &SuperTrap::operator=(SuperTrap const & rhs)
{
	ClapTrap::operator=(rhs);
	std::cout << "* SUPER-TRAP * Assigning Operator Called: < " << this->_Name << " > I'm a deadeye like Mordecai!" << std::endl << std::endl;
	return (*this);
}