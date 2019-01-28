/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 07:57:17 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/03 12:53:08 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

int     main(void){

// while(1){

    std::cout << "Zombie on Stack" << std::endl;
	Zombie	Walking = Zombie("Walking", "TV SHOW");

	std::cout << std::endl << "ZombieEvent on Heap" << std::endl;
	ZombieEvent	*PatientZero = new ZombieEvent();

	std::cout << std::endl << "Setting Zombie type to Singer" << std::endl;
	PatientZero->setZombietype_("Singer");

	std::cout << std::endl << "Setting Zombie type With nothing" << std::endl;
	PatientZero->setZombietype_("");

    Zombie  *Frist;
	std::cout << std::endl << "Spawning ZombieEvent with same Type" << std::endl;
	Frist = PatientZero->newZombie("PatientOne");

	std::cout << std::endl << "Changing All zombietypeEvent to Power" << std::endl;
	PatientZero->setZombietype_("Power");

	if(Frist)
		delete Frist;
	std::cout << std::endl << "Spawning ZombieEvent with random name but same type" << std::endl;
	Frist = PatientZero->randomChump();

	std::cout << std::endl << "Spawning another Zombie on Heap" << std::endl;
	Zombie *WalkingDead2 = new Zombie("WalkingDead2", "PrinceOfWorld");

	std::cout << std::endl << "Destory all zombies." << std::endl;
	std::cout << std::endl << "In order WalkingDead2 (Heap), All Zombie create with Events(Heap), Walking (stack)" << std::endl << std::endl;
	
	if(WalkingDead2)
		delete WalkingDead2;
    if(Frist)
		delete Frist;
	if(PatientZero)
		delete PatientZero;
// }
	return (0);
}