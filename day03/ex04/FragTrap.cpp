/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 08:30:34 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/05 16:48:08 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

//CONSTRUCTOR
//------------------------
// Init Construtor
FragTrap::FragTrap(void)
{
    srand(time(0));
	this->set_Stats("* FR4G-TPAP *", 1, 100, 100, 100, 100, 30, 20, 5);
    std::cout << "* FR4G-TPAP * Default Constructor Called! <" << ClapTrap::magenta << this->_Name << ClapTrap::reset << ".Fragtap> : Hey everybody! Check out my package!" << std::endl;
    return;
}
// Constructor with name paramettre
FragTrap::FragTrap(std::string name) 
{
    srand(time(0));
	this->set_Stats(name, 1, 100, 100, 100, 100, 30, 20, 5);
    std::cout << "* FR4G-TPAP * Parameter Constructor Called! <" << ClapTrap::magenta << this->_Name << ClapTrap::reset << ".Fragtap> : Let's get this party started!" << std::endl;
    return;
}

// Copy Constructor
FragTrap::FragTrap(FragTrap const &src)
{
    srand(time(0));
    std::cout << "* FR4G-TPAP * Copy constructor called! You. Are. Not. Dead! Now shut the hell up!" << std::endl;
    std::cout << "<" << ClapTrap::magenta << this->_Name << ClapTrap::reset << ".Fragtap> : This time it'll be awesome, I promise!" << std::endl;
    *this = src;
    return;
}

FragTrap::~FragTrap(void)
{
    std::cout << "* FR4G-TPAP * Destructor Called: <" << ClapTrap::magenta << this->_Name << ClapTrap::reset << ".Fragtap> I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
    return;
}

FragTrap & FragTrap::operator=( FragTrap const & rhs )
{
    ClapTrap::operator=(rhs);
    std::cout << "* FR4G-TPAP * Assigning Operator = Called : <" << ClapTrap::magenta << this->_Name << ClapTrap::reset << ".Fragtap> Thanks for giving me a second chance, God. I really appreciate it." << std::endl
              << std::endl;
    return (*this);
}


void	FragTrap::vaulthunter_dot_exe( std::string const & target )
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

	if (get_Energy_points() < 25)
	{
		std::cout << "* FR4G-TPAP * <" << ClapTrap::magenta << this->_Name << ClapTrap::reset << "> does not have enough energy points! Current energy " <<
			this->get_Energy_points() << " / " << this->get_Max_energy_points() << std::endl << std::endl;
		return;
	}
	else
		this->set_Energy_points(this->get_Energy_points() - 25);
	std::cout << "* FR4G-TPAP * <" << ClapTrap::magenta << this->_Name << ClapTrap::reset << "> uses VaultHunter.Exe! Let's see it's real powers!" << std::endl;
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

void	FragTrap::one_Shot_Wonder(std::string const & target)
{
	std::cout << "* FR4G-TPAP * <" << ClapTrap::magenta << this->_Name << ClapTrap::reset << "> uses One Shot Wonder! The effect extends to Claptrap's allies!" << std::endl
              << "With his One Shot Wonder One pull of the trigger unloads all ammo left in the magazine at once and knocks Claptrap back, inflicting increased melee damage x50" << std::endl 
              << ClapTrap::red << target << ClapTrap::reset << " takes " << this->get_Hit_points() * 5.0f << " damage !" << std::endl
              << "<" << ClapTrap::magenta << this->_Name << ClapTrap::reset << "> : " << this->annouce_one_Shot_Wonder() << std::endl
              << std::endl;
	return;
}

void	FragTrap::rubber_Ducky(std::string const &target)
{
	(void)target;
	this->set_Max_hit_points(this->get_Max_hit_points() * 1.5);
	std::cout << "* FR4G-TPAP * <" << ClapTrap::magenta << this->_Name << ClapTrap::reset << "> uses Rubber Ducky!." << std::endl
              << "With his rubber ducky his max health has increased by 1.5x!" << std::endl 
              <<" New Max Health " << ClapTrap::green << this->get_Max_hit_points() << ClapTrap::reset << std::endl
		      << "<" << ClapTrap::magenta << this->_Name << ClapTrap::reset << "> : " << this->annouce_rubber_Ducky() << std::endl
              << std::endl;
	return;
}

void	FragTrap::shhhh_Trap(std::string const &target)
{
	(void)target;
	this->set_Armor_damage_reduction(this->get_Armor_damage_reduction() * 5);
	std::cout << "* FR4G-TPAP * <" << ClapTrap::magenta << this->_Name << ClapTrap::reset << "> deploys a Holotrap, add Armor reduction damage and becomes invisible" << std::endl
		      << "<" << ClapTrap::magenta << this->_Name << ClapTrap::reset << "> : Ooh yeah, watch me! Watch me go!" << std::endl
		      << "<" << ClapTrap::magenta << this->_Name << ClapTrap::reset << "> : " << this->annouce_shhhh_Trap() << std::endl
              << std::endl;
	return;
}

void	FragTrap::funzerker(std::string const &target)
{
	std::cout << "* FR4G-TPAP * <" << ClapTrap::magenta << this->_Name << ClapTrap::reset << "> uses Funzerker!" << std::endl
              << "Get copy of his currently equipped weapon in his other clamp" << std::endl
              << "+50%% fire rate and +100%% reload speed."
		      << target << " takes " << this->get_Ranged_attack_damage() * 0.5f << " damage !" << std::endl
		      << "<" << ClapTrap::magenta << this->_Name << ClapTrap::reset << "> : " << this->annouce_funzerker() << std::endl
              << std::endl;
	return;
}

void	FragTrap::mechromagician(std::string const &target)
{
	std::cout << "* FR4G-TPAP * <" << ClapTrap::magenta << this->_Name << ClapTrap::reset << "> uses Mechromagician !" << std::endl 
              << "Gun damage is increased by approximately 263%%" << std::endl
              << target << " takes " << this->get_Ranged_attack_damage() * 2.63f << " damage !" << std::endl
              << "<" << ClapTrap::magenta << this->_Name << ClapTrap::reset << "> : " << this->annouce_mechromagician() << std::endl
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

