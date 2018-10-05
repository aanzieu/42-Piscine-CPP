/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 13:06:00 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/05 15:39:06 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) :
        _Name("* CL4P-TR4P *"),
        _Hit_points(100),
        _Max_hit_points(100),
        _Energy_points(100),
        _Max_energy_points(100),
        _Level(1),
        _Melee_attack_damage(30),
        _Ranged_attack_damage(20),
        _Armor_damage_reduction(5)
{
    srand(time(0));
    std::cout << "* CL4P-TR4P * Default Constructor Called! <" << this->_Name << ".ClapTrap> : Chikchkit chkit !" << std::endl;
    return;
}
// Constructor with name paramettre
ClapTrap::ClapTrap(std::string name) : 
    _Name(name),
    _Hit_points(100),
    _Max_hit_points(100),
    _Energy_points(100),
    _Max_energy_points(100),
    _Level(1),
    _Melee_attack_damage(30),
    _Ranged_attack_damage(20),
    _Armor_damage_reduction(5)
{
    srand(time(0));
    std::cout << "* CL4P-TR4P * Parameter Constructor Called! <" << this->_Name << ".ClapTrap> : Hello Beauty !" << std::endl;
    return;
}

// Copy Constructor
ClapTrap::ClapTrap(ClapTrap const &src)
{
    srand(time(0));
    std::cout << "* CL4P-TR4P * Copy constructor called! " << std::endl;
    std::cout << "<" << this->_Name << ".ClapTrap> : Clap-Trap is Here" << std::endl;
    *this = src;
    return;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "* CL4P-TR4P * Destructor Called: <" << this->_Name << ".ClapTrap> Clav-Trap - dead" << std::endl;
    return;
}

ClapTrap & ClapTrap::operator=( ClapTrap const & rhs )
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
    std::cout << "Assigning Operator = Called : <" << this->_Name << ".ClapTrap>  Clap-Trap COPY IT COPY IT !." << std::endl
              << std::endl;
    return (*this);
}







// FUNCTiONS
// ---------------------
// Range Attack
void ClapTrap::rangedAttack( std::string const &target )
{
    std::cout << "<" << ClapTrap::yellow << this->_Name << ClapTrap::reset << "> attacks <" << target << "> at range, causing "
              << this->_Ranged_attack_damage << "points of damage !" << std::endl;
    std::cout << "<" << ClapTrap::yellow << this->_Name << ClapTrap::reset << "> : Do you have a family ?" << std::endl << std::endl;
    return;
}
// Melle Attack
void	ClapTrap::meleeAttack( std::string const & target )
{
	std::cout << "<" << ClapTrap::yellow << this->_Name << ClapTrap::reset << "> attacks " << target << " at melee, causing "
              << this->_Melee_attack_damage << " points of damage !" << std::endl;
    std::cout << "<" << ClapTrap::yellow << this->_Name << ClapTrap::reset << "> Oups Sorry!" << std::endl << std::endl;
	return;
}

void	ClapTrap::displayStats(void) const
{
	std::cout << "<" << ClapTrap::red << this->_Name << ClapTrap::reset << "> STATS:" << std::endl <<
		"Level: " << this->_Level << std::endl <<
		"Life: " << this->_Hit_points << " / " << this->_Max_hit_points << std::endl <<
		"Energy: " << this->_Energy_points << " / " << this->_Max_energy_points << std::endl <<
		"Melee Attack: " << this->_Melee_attack_damage << std::endl <<
		"Ranged Attack: " << this->_Ranged_attack_damage << std::endl <<
		"Armor: " << this->_Armor_damage_reduction << std::endl << std::endl;
	return;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	int i = 0;

	if (amount > (unsigned int)(this->_Max_hit_points + this->_Armor_damage_reduction))
		i = this->_Max_hit_points + this->_Armor_damage_reduction;
	else
		i = amount;
	this->_Hit_points = this->_Hit_points - i + this->_Armor_damage_reduction;
	if (this->_Hit_points < 0)
		this->_Hit_points = 0;
	std::cout << "<" << this->_Name << "> took " << amount << " of damage" << std::endl 
              << "Armor blocked " << this->_Armor_damage_reduction << " points of damage." << std::endl
              << "Current health : " << this->_Hit_points << " / " << this->_Max_hit_points << std::endl;
	if (this->_Hit_points == 0)
		std::cout << "<" << this->_Name << "> ARRRRHHHHHHH!!! See you Soon !" << std::endl << std::endl;
	else
		std::cout << "<" << this->_Name << "> Ahah miss me ? wait." << std::endl << std::endl;
	return;
}

void	ClapTrap::beRepaired(unsigned int amount)
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
	std::cout << "<" << this->_Name << "> recovery " << healed << " health back. " << std::endl
              << "Current health : " << this->_Hit_points << " / " << this->_Max_hit_points << std::endl
              << "<" << this->_Name << "> Health! Eww, what flavor is red? " << std::endl << std::endl;
	return;
}




void	ClapTrap::set_Stats(std::string name, 
                        int lvl, int hp, int max_hp, int ep, 
                        int max_ep, int melle_atk, int range_atk, 
                        int armor)
{
	this->_Name = name;
	this->_Level = lvl;
	this->_Hit_points = hp;
	this->_Max_hit_points = max_hp;
	this->_Energy_points = ep;
	this->_Max_energy_points = max_ep;
	this->_Melee_attack_damage = melle_atk;
	this->_Ranged_attack_damage = range_atk;
	this->_Armor_damage_reduction = armor;
	return;
}



// Set All Informations
void	ClapTrap::set_Hit_points(int i)
{
	this->_Hit_points = i;
	return;
}
void	ClapTrap::set_Max_hit_points(int i)
{
	this->_Max_hit_points = i;
	return;
}
void	ClapTrap::set_Energy_points(int i)
{
	this->_Energy_points = i;
	return;
}
void	ClapTrap::set_Max_energy_points(int i)
{
	this->_Max_energy_points = i;
	return;
}
void	ClapTrap::set_Level(int i)
{
	this->_Level = i;
	return;
}
void	ClapTrap::set_Melee_attack_damage(int i)
{
	this->_Melee_attack_damage = i;
	return;
}
void	ClapTrap::set_Ranged_attack_damage(int i)
{
	this->_Ranged_attack_damage = i;
	return;
}
void	ClapTrap::set_Armor_damage_reduction(int i)
{
	this->_Armor_damage_reduction = i;
	return;
}


// Get All Information
std::string	ClapTrap::get_Name( void ) const
{
	return this->_Name;
}
int	ClapTrap::get_Hit_points( void ) const
{
	return this->_Hit_points;
}
int	ClapTrap::get_Max_hit_points( void ) const 
{
	return this->_Max_hit_points;
}
int	ClapTrap::get_Energy_points( void ) const
{
	return this->_Energy_points;
}
int	ClapTrap::get_Max_energy_points( void ) const
{
	return this->_Max_energy_points;
}
int	ClapTrap::get_Level( void ) const
{
	return this->_Level;
}
int	ClapTrap::get_Melee_attack_damage( void ) const
{
	return this->_Melee_attack_damage;
}
int	ClapTrap::get_Ranged_attack_damage( void ) const
{
	return this->_Ranged_attack_damage;
}
int	ClapTrap::get_Armor_damage_reduction( void ) const
{
	return this->_Armor_damage_reduction;
}

const std::string ClapTrap::red = "\033[0;31m";
const std::string ClapTrap::green = "\033[1;32m";
const std::string ClapTrap::yellow = "\033[1;33m";
const std::string ClapTrap::cyan = "\033[0;36m";
const std::string ClapTrap::magenta = "\033[0;35m";
const std::string ClapTrap::reset = "\033[0m";
