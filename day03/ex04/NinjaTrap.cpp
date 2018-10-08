/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 08:30:34 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/05 16:34:33 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"

//CONSTRUCTOR
//------------------------
// Init Construtor
NinjaTrap::NinjaTrap(void)
{
    srand(time(0));
    ClapTrap::set_Stats("* NINJ4-TRAP *" ,1, 60, 60, 120, 120, 60, 5, 0);
    std::cout << "* NINJ4-TRAP * Default Constructor Called! <"  << ClapTrap::cyan << this->_Name  << ClapTrap::reset << ".NinjaTrap> : Naruto love." << std::endl;
    return;
}
// Constructor with name paramettre
NinjaTrap::NinjaTrap(std::string name)
{

    srand(time(0));
    ClapTrap::set_Stats(name, 1, 60, 60, 120, 120, 60, 5, 0);
    std::cout << "* NINJ4-TRAP * Parameter Constructor Called! <" << ClapTrap::cyan << this->_Name  << ClapTrap::reset << ".NinjaTrap> : Naruto love. " << std::endl;
    return;
}

// Copy Constructor
NinjaTrap::NinjaTrap(NinjaTrap const & src)
{
    srand(time(0));
    std::cout << "* NINJ4-TRAP * Copy constructor called! Dismissed!" << std::endl;
    std::cout << "<"  << ClapTrap::cyan << this->_Name  << ClapTrap::reset << ".NinjaTrap> : Multiclonage " << std::endl;
    *this = src;
    return;
}

NinjaTrap::~NinjaTrap(void)
{
    std::cout << "* NINJ4-TRAP * Destructor Called: <"  << ClapTrap::cyan << this->_Name  << ClapTrap::reset << ".NinjaTrap> I'm a ninja dead" << std::endl;
    return;
}

NinjaTrap & NinjaTrap::operator=( NinjaTrap const & rhs )
{
    ClapTrap::operator=(rhs);
    std::cout << "* NINJ4-TRAP * Assigning Operator = Called : <" 
			   << ClapTrap::cyan << this->_Name  << ClapTrap::reset << ".NinjaTrap> Ninga Go Lego Lego !" << std::endl
              << std::endl;
    return (*this);
}


// ShowBox Other Class 

void	NinjaTrap::ninjaShoeBox(ClapTrap const & rhs)
{
	std::cout << "< "  << ClapTrap::cyan << this->_Name  << ClapTrap::reset << " > A claptrap feels no pain- ow! Quit it! " << ClapTrap::green << rhs.get_Name() << ".ClapTrap " << std::endl;
    return;
}

void	NinjaTrap::ninjaShoeBox(FragTrap  & rhs)
{
	std::cout << "< "  << ClapTrap::cyan << this->_Name  << ClapTrap::reset << " > Hey! Knock it off!  " << ClapTrap::green << rhs.get_Name() << ".FragTrap" << std::endl;
    rhs.takeDamage((unsigned int)this->get_Melee_attack_damage());
    return;	
}

void	NinjaTrap::ninjaShoeBox(NinjaTrap const & rhs)
{
	std::cout << "< "  << ClapTrap::cyan << this->_Name  << ClapTrap::reset << " >  I'm taking fire! " << ClapTrap::green << rhs.get_Name() << ".NinjaTrap" << std::endl;
	return;	
}

void	NinjaTrap::ninjaShoeBox(ScavTrap const & rhs)
{
	std::cout << "< "  << ClapTrap::cyan << this->_Name  << ClapTrap::reset << " > Don't like you "  << ClapTrap::green << rhs.get_Name() << ".ScavTrap" << std::endl;
	return;	
}