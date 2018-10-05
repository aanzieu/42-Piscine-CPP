/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 11:08:15 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/05 13:58:48 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"


void		show_status(ClapTrap const & o){

	o.displayStats();
}

int	main()
{
	FragTrap fragrobot;
	ScavTrap scavrobot;


	scavrobot.meleeAttack("Poney-2");
	scavrobot.rangedAttack("Zombie-2");

	fragrobot.meleeAttack("Poney-1");
	fragrobot.rangedAttack("Zombie-1");

	fragrobot.takeDamage(30);
	fragrobot.beRepaired(10);

	scavrobot.takeDamage(30);
	scavrobot.beRepaired(10);

	show_status(fragrobot);
	show_status(scavrobot);

	scavrobot.displayStats();

	fragrobot.vaulthunter_dot_exe("Skags");
	scavrobot.challengeNewcomer("ASS HOLE");
	
	return (0);
}