/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 11:08:15 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/05 11:21:29 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main()
{
	FragTrap robot, robot2("Clancy"), robot3("Mosby");

	robot.meleeAttack("Poney's");
	robot2.rangedAttack("Otter's");
	robot.takeDamage(50);
	robot.beRepaired(50);
	robot.takeDamage(104);
    robot.beRepaired(90);
	robot.beRepaired(20);

	robot2.meleeAttack("Robot");
	robot.takeDamage(30);

	robot.vaulthunter_dot_exe("otter");
	robot2.vaulthunter_dot_exe("otter new");
	robot.vaulthunter_dot_exe("Zombie");
	robot3.vaulthunter_dot_exe("Horde of Zombie");

	robot.displayStats();
	robot2.displayStats();
	robot3.displayStats();
	
	return (0);
}