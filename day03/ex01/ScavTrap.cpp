/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 08:30:34 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/05 12:07:12 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//CONSTRUCTOR
//------------------------
// Init Construtor
ScavTrap::ScavTrap(void) : _Hit_points(100),
                           _Max_hit_points(100),
                           _Energy_points(50),
                           _Max_energy_points(50),
                           _Level(1),
                           _Name("SC4-TP"),
                           _Melee_attack_damage(20),
                           _Ranged_attack_damage(15),
                           _Armor_damage_reduction(3)
{

    srand(time(0));
    std::cout << "Default Constructor Called! <" << this->_Name << ".ScavTrap> : I need a briefing." << std::endl;
    return;
}
// Constructor with name paramettre
ScavTrap::ScavTrap(std::string name) : _Hit_points(100),
                                       _Max_hit_points(100),
                                       _Energy_points(50),
                                       _Max_energy_points(50),
                                       _Level(1),
                                       _Name(name),
                                       _Melee_attack_damage(20),
                                       _Ranged_attack_damage(15),
                                       _Armor_damage_reduction(3)
{

    srand(time(0));
    std::cout << "Parameter Constructor Called! <" << this->_Name << ".ScavTrap> : What's the situation?" << std::endl;
    return;
}

// Copy Constructor
ScavTrap::ScavTrap(ScavTrap const &src)
{
    srand(time(0));
    std::cout << "Copy constructor called! Dismissed!" << std::endl;
    std::cout << "<" << this->_Name << ".ScavTrap> : What are you waiting for? Get going." << std::endl;
    *this = src;
    return;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "Destructor Called: <" << this->_Name << ".ScavTrap> Why are we killing me again?" << std::endl;
    return;
}

ScavTrap & ScavTrap::operator=( ScavTrap const & rhs )
{
    this->_Hit_points = rhs._Hit_points;
    this->_Max_hit_points = rhs._Max_hit_points;
    this->_Energy_points = rhs._Energy_points;
    this->_Max_energy_points = rhs._Max_energy_points;
    this->_Level = rhs._Level;
    this->_Name = rhs._Name;
    this->_Melee_attack_damage = rhs._Melee_attack_damage;
    this->_Ranged_attack_damage = rhs._Ranged_attack_damage;
    this->_Armor_damage_reduction = rhs._Armor_damage_reduction;
    std::cout << "Assigning Operator = Called : <" << this->_Name << ".ScavTrap> We are Same We Are Same !!! Like it like it !" << std::endl
              << std::endl;
    return (*this);
}


// FUNCTiONS
// ---------------------
// Range Attack
void ScavTrap::rangedAttack( std::string const &target )
{

    std::cout << "SC4V-TP <" << this->_Name << "> attacks <" << target << "> at range, causing "
              << this->_Ranged_attack_damage << "points of damage !" << std::endl;
    std::cout << "<" << this->_Name << "> : Do you have a family ?" << std::endl << std::endl;
    return;
}
// Melle Attack
void	ScavTrap::meleeAttack( std::string const & target )
{
	std::cout << "SC4V-TP <" << this->_Name << "> attacks " << target << " at melee, causing "
              << this->_Melee_attack_damage << " points of damage !" << std::endl;
    std::cout << "<" << this->_Name << "> Oups Sorry!" << std::endl << std::endl;
	return;
}

void	ScavTrap::displayStats(void) const
{
	std::cout << "SC4V-TP <" << this->_Name << "> STATS:" << std::endl <<
		"Level: " << this->_Level << std::endl <<
		"Life: " << this->_Hit_points << " / " << this->_Max_hit_points << std::endl <<
		"Energy: " << this->_Energy_points << " / " << this->_Max_energy_points << std::endl <<
		"Melee Attack: " << this->_Melee_attack_damage << std::endl <<
		"Ranged Attack: " << this->_Ranged_attack_damage << std::endl <<
		"Armor: " << this->_Armor_damage_reduction << std::endl << std::endl;
	return;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	int i = 0;

	if (amount > (unsigned int)(this->_Max_hit_points + this->_Armor_damage_reduction))
		i = this->_Max_hit_points + this->_Armor_damage_reduction;
	else
		i = amount;
	this->_Hit_points = this->_Hit_points - i + this->_Armor_damage_reduction;
	if (this->_Hit_points < 0)
		this->_Hit_points = 0;
	std::cout << "SC4V-TP <" << this->_Name << "> took " << amount << " of damage" << std::endl 
              << "Armor blocked " << this->_Armor_damage_reduction << " points of damage." << std::endl
              << "Current health : " << this->_Hit_points << " / " << this->_Max_hit_points << std::endl;
	if (this->_Hit_points == 0)
		std::cout << "<" << this->_Name << "> ARRRRHHHHHHH!!! See you Soon !" << std::endl << std::endl;
	else
		std::cout << "<" << this->_Name << "> Ahah miss me ? wait." << std::endl << std::endl;
	return;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	int healed = 0;

	if (amount > (unsigned int)this->_Max_hit_points)
		amount = (unsigned int)this->_Max_hit_points;
	if ((this->_Hit_points + amount) > (unsigned int)this->_Max_hit_points)
	{
		healed = ((this->_Hit_points + amount) - this->_Max_hit_points) - amount;
		if (healed < 0)
			healed *= -1;
	}
	else
		healed = amount;
	this->_Hit_points += amount;
	if (this->_Hit_points > this->_Max_hit_points)
		this->_Hit_points = this->_Max_hit_points;
	std::cout << "SC4V-TP <" << this->_Name << "> recovery " << healed << " health back. " << std::endl
              << "Current health : " << this->_Hit_points << " / " << this->_Max_hit_points << std::endl
              << "<" << this->_Name << "> Health! Eww, what flavor is red? " << std::endl << std::endl;
	return;
}

void	ScavTrap::challengeNewcomer(std::string const & target)
{
	int i = rand();
	std::cout << "<" << this->_Name << ">" << " challenges the newcomer <" << target << "> : ";
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