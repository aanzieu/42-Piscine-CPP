/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 11:08:15 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/05 15:46:09 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int	main()
{
	FragTrap fragrobot("Baltazar");
	ScavTrap scavrobot("OreArson");
	NinjaTrap ninjago("Naruto Boy");

	// scavrobot.meleeAttack("Poney-2");
	ninjago.ninjaShoeBox(scavrobot);
	ninjago.meleeAttack(scavrobot.get_Name());
	scavrobot.rangedAttack(ninjago.get_Name());


	ninjago.ninjaShoeBox(fragrobot);
	ninjago.meleeAttack(fragrobot.get_Name());
	fragrobot.meleeAttack(ninjago.get_Name());

	// fragrobot.rangedAttack("Zombie-1");

	// fragrobot.takeDamage(30);
	// fragrobot.beRepaired(10);

	ninjago.takeDamage(30);
	ninjago.beRepaired(10);

	ninjago.displayStats();

	// fragrobot.vaulthunter_dot_exe("Skags");
	// scavrobot.challengeNewcomer("ASS HOLE");
	
	return (0);
}