/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 11:08:15 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/05 17:04:41 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int	main()
{
	SuperTrap superrobot("Baltazar");
	NinjaTrap Narutoboy("NARUTO");
	
	// superrobot.meleeAttack("Poney-2");
	superrobot.ninjaShoeBox(Narutoboy);
	superrobot.meleeAttack(superrobot.get_Name());
	superrobot.rangedAttack(superrobot.get_Name());

	superrobot.ninjaShoeBox(Narutoboy);
	superrobot.meleeAttack(superrobot.get_Name());
	superrobot.meleeAttack(superrobot.get_Name());

	// superrobot.rangedAttack("Zombie-1");

	// superrobot.takeDamage(30);
	// superrobot.beRepaired(10);

	// superrobot.takeDamage(30);
	// superrobot.beRepaired(10);
	superrobot.displayStats();
	superrobot.displayStats();

	// superrobot.vaulthunter_dot_exe("Skags");
	// superrobot.challengeNewcomer("ASS HOLE");
	
	return (0);
}