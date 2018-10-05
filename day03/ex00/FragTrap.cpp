/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 08:30:34 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/05 12:09:03 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//CONSTRUCTOR
//------------------------
// Init Construtor
FragTrap::FragTrap(void) : _Hit_points(100),
                           _Max_hit_points(100),
                           _Energy_points(100),
                           _Max_energy_points(100),
                           _Level(1),
                           _Name("FR4G-TP"),
                           _Melee_attack_damage(30),
                           _Ranged_attack_damage(20),
                           _Armor_damage_reduction(5)
{

    srand(time(0));
    std::cout << "Default Constructor Called! <" << this->_Name << ".Fragtap> : Hey everybody! Check out my package!" << std::endl;
    return;
}
// Constructor with name paramettre
FragTrap::FragTrap(std::string name) : _Hit_points(100),
                                       _Max_hit_points(100),
                                       _Energy_points(100),
                                       _Max_energy_points(100),
                                       _Level(1),
                                       _Name(name),
                                       _Melee_attack_damage(30),
                                       _Ranged_attack_damage(20),
                                       _Armor_damage_reduction(5)
{

    srand(time(0));
    std::cout << "Parameter Constructor Called! <" << this->_Name << ".Fragtap> : Let's get this party started!" << std::endl;
    return;
}

// Copy Constructor
FragTrap::FragTrap(FragTrap const &src)
{
    srand(time(0));
    std::cout << "Copy constructor called! You. Are. Not. Dead! Now shut the hell up!" << std::endl;
    std::cout << "<" << this->_Name << ".Fragtap> : This time it'll be awesome, I promise!" << std::endl;
    *this = src;
    return;
}

FragTrap::~FragTrap(void)
{
    std::cout << "Destructor Called: <" << this->_Name << ".Fragtap> I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
    return;
}

FragTrap & FragTrap::operator=( FragTrap const & rhs )
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
    std::cout << "Assigning Operator = Called : <" << this->_Name << ".Fragtap> Thanks for giving me a second chance, God. I really appreciate it." << std::endl
              << std::endl;
    return (*this);
}


// FUNCTiONS
// ---------------------
// Range Attack
void FragTrap::rangedAttack( std::string const &target )
{

    std::cout << "FR4G-TP <" << this->_Name << "> attacks <" << target << "> at range, causing "
              << this->_Ranged_attack_damage << "points of damage !" << std::endl;
    std::cout << "<" << this->_Name << "> : RUN FOR YOUR LIIIIIVES!!!" << std::endl << std::endl;
    return;
}
// Melle Attack
void	FragTrap::meleeAttack( std::string const & target )
{
	std::cout << "FR4G-TP <" << this->_Name << "> attacks " << target << " at melee, causing "
              << this->_Melee_attack_damage << " points of damage !" << std::endl;
    std::cout << "<" << this->_Name << "> Heyyah!" << std::endl << std::endl;
	return;
}

void	FragTrap::displayStats(void) const
{
	std::cout << "FR4G-TP <" << this->_Name << "> STATS:" << std::endl <<
		"Level: " << this->_Level << std::endl <<
		"Life: " << this->_Hit_points << " / " << this->_Max_hit_points << std::endl <<
		"Energy: " << this->_Energy_points << " / " << this->_Max_energy_points << std::endl <<
		"Melee Attack: " << this->_Melee_attack_damage << std::endl <<
		"Ranged Attack: " << this->_Ranged_attack_damage << std::endl <<
		"Armor: " << this->_Armor_damage_reduction << std::endl << std::endl;
	return;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	int i = 0;

	if (amount > (unsigned int)(this->_Max_hit_points + this->_Armor_damage_reduction))
		i = this->_Max_hit_points + this->_Armor_damage_reduction;
	else
		i = amount;
	this->_Hit_points = this->_Hit_points - i + this->_Armor_damage_reduction;
	if (this->_Hit_points < 0)
		this->_Hit_points = 0;
	std::cout << "FR4G-TP <" << this->_Name << "> took " << amount << " of damage" << std::endl 
              << "Armor blocked " << this->_Armor_damage_reduction << " points of damage." << std::endl
              << "Current health : " << this->_Hit_points << " / " << this->_Max_hit_points << std::endl;
	if (this->_Hit_points == 0)
		std::cout << "<" << this->_Name << "> Don't forget me!" << std::endl << std::endl;
	else
		std::cout << "<" << this->_Name << "> Why do I even feel pain?" << std::endl << std::endl;
	return;
}

void	FragTrap::beRepaired(unsigned int amount)
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
	std::cout << "FR4G-TP <" << this->_Name << "> recovery " << healed << " health back. " << std::endl
              << "Current health : " << this->_Hit_points << " / " << this->_Max_hit_points << std::endl
              << "<" << this->_Name << "> Health! Eww, what flavor is red? " << std::endl << std::endl;
	return;
}



void	FragTrap::vaulthunter_dot_exe( std::string const &target )
{
	int i = rand();
	int x = 0;

    typedef void    (FragTrap::*Special_Attack)(std::string const & target);
	
    Special_Attack      Chooser_attack[5] = {
		&FragTrap::mechromagician,
		&FragTrap::shhhh_Trap,
		&FragTrap::funzerker,
		&FragTrap::rubber_Ducky,
		&FragTrap::one_Shot_Wonder
	};

	if (this->_Energy_points < 25)
	{
		std::cout << "FR4G-TP <" << this->_Name << "> does not have enough energy points! Current energy " <<
			this->_Energy_points << " / " << this->_Max_energy_points << std::endl << std::endl;
		return;
	}
	else
		this->_Energy_points = this->_Energy_points - 25;
	std::cout << "FR4G-TP <" << this->_Name << "> uses VaultHunter.Exe! Let's see it's real powers!" << std::endl;
	i = (i % 5);
	while (x < 5)
	{
		if (x == i)
		{
			(this->*Chooser_attack[i])(target);
            break;
		}
		x++;
	}
	return;
}

void	FragTrap::one_Shot_Wonder(std::string const &target)
{
	std::cout << "FR4G-TP <" << this->_Name << "> uses One Shot Wonder! The effect extends to Claptrap's allies!" << std::endl
              << "With his One Shot Wonder One pull of the trigger unloads all ammo left in the magazine at once and knocks Claptrap back, inflicting increased melee damage x50" << std::endl 
              << target << " takes " << this->_Melee_attack_damage * 5.0f << " damage !" << std::endl
              << "<" << this->_Name << "> : " << this->annouce_one_Shot_Wonder() << std::endl
              << std::endl;
	return;
}

void	FragTrap::rubber_Ducky(std::string const &target)
{
	(void)target;
	this->_Max_hit_points = this->_Max_hit_points * 1.5;
	std::cout << "FR4G-TP <" << this->_Name << "> uses Rubber Ducky!." << std::endl
              << "With his rubber ducky his max health has increased by 1.5x!" << std::endl 
              <<" New Max Health " << this->_Max_hit_points << std::endl
		      << "<" << this->_Name << "> : " << this->annouce_rubber_Ducky() << std::endl
              << std::endl;
	return;
}

void	FragTrap::shhhh_Trap(std::string const &target)
{
	(void)target;
	this->_Armor_damage_reduction *= 5;
	std::cout << "FR4G-TP <" << this->_Name << "> deploys a Holotrap, add Armor reduction damage and becomes invisible" << std::endl
		      << "<" << this->_Name << "> : Ooh yeah, watch me! Watch me go!" << std::endl
		      << "<" << this->_Name << "> : " << this->annouce_shhhh_Trap() << std::endl
              << std::endl;
	return;
}

void	FragTrap::funzerker(std::string const &target)
{
	std::cout << "FR4G-TP <" << this->_Name << "> uses Funzerker!" << std::endl
              << "Get copy of his currently equipped weapon in his other clamp" << std::endl
              << "+50%% fire rate and +100%% reload speed."
		      << target << " takes " << this->_Ranged_attack_damage * 0.5f << " damage !" << std::endl
		      << "<" << this->_Name << "> : " << this->annouce_funzerker() << std::endl
              << std::endl;
	return;
}

void	FragTrap::mechromagician(std::string const &target)
{
	std::cout << "FR4G-TP <" << this->_Name << "> uses Mechromagician !" << std::endl 
              << "Gun damage is increased by approximately 263%%" << std::endl
              << target << " takes " << this->_Ranged_attack_damage * 2.63f << " damage !" << std::endl
              << "<" << this->_Name << "> : " << this->annouce_mechromagician() << std::endl
              << std::endl;
	return;
}



// ANNOUCCE
//------------------
std::string     FragTrap::annouce_funzerker(void) const{
    int i = rand();
    return FragTrap::_annouce_funzerker[i % 4];
}
std::string	    FragTrap::annouce_mechromagician( void  ) const{
    int i = rand();
    return FragTrap::_annouce_mechromagician[i % 5];
}
std::string	    FragTrap::annouce_shhhh_Trap( void  ) const {
    int i = rand();
    return FragTrap::_annouce_shhhh_Trap[i % 5];
}
std::string	    FragTrap::annouce_rubber_Ducky( void  ) const{
    int i = rand();
    return FragTrap::_annouce_rubber_Ducky[i % 5];
}
std::string	    FragTrap::annouce_one_Shot_Wonder( void ) const{
    int i = rand();
    return FragTrap::_annouce_one_Shot_Wonder[i % 5];
}


// ANNOUCE RANDOM
//---------------------
std::string      FragTrap::_annouce_funzerker[4] = {
    "I'm a sexy dinosaur! Rawr!",
    "Oh god I can't stop!",
    "Don't ask me where this ammo's coming from!",
    "If I had veins, they'd be popping out right now!"
};

std::string      FragTrap::_annouce_mechromagician[5] = {
   "To the skies, mini-trap!",
    "Fly mini-trap! Fly!",
    "I have two robot arms!",
    "Punch 'em in the face, mini-trap!",
    "Anarchy and mini-trap and awesomeness, oh my!"
};
std::string      FragTrap::_annouce_shhhh_Trap[5] = {
    "I'm cloaking...",
    "Roses are red and/Violets are blue/Wait... how many syllables was that?",
    "Shoot him... he's the real one...",
    "I'm a robot ninja...",
    "I'm invisible!"
};

std::string      FragTrap::_annouce_rubber_Ducky[5] = {
    "Boiyoiyoiyoiyoing!",
    "Zing! Bullet reflection!",
    "I am rubber, and you are so dead!",
    "I'm a superball!",
    "Trouncy, flouncy... founcy... those aren't words."
};
std::string      FragTrap::_annouce_one_Shot_Wonder[5] = {
   "Kill, reload! Kill, reload! KILL! RELOAD!",
    "Like those guys who made only one song ever.",
    "All these bullets in just one shot.",
    "One shot, make it count!",
    "A whole lotta bullets in just one trigger pull!"
};

