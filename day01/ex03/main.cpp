/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 07:57:17 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/03 11:22:56 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

int     main(void){

	ZombieHorde *Horde = new ZombieHorde(100);
	Horde->announce_All_Zombies();
	delete Horde;


	return (0);
}