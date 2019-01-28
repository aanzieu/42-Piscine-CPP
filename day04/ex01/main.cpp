/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:29:08 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/06 12:04:36 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"
#include "Character.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

int main()
{
    Character *zaz = new Character("zaz");

    std::cout << *zaz;
    Enemy *supermute = new SuperMutant();
    
    Enemy *scorpion = new RadScorpion();
    AWeapon *plasma = new PlasmaRifle();
    
    AWeapon *powerfist = new PowerFist();
    
    zaz->equip(plasma);
    
    std::cout << *zaz;
    
    zaz->equip(powerfist);
    
    std::cout << *zaz;

    zaz->attack(scorpion);
    
    std::cout << *zaz;
    
    
    zaz->attack(scorpion);
    std::cout << *zaz;

    std:: cout << supermute->getHP() << std::endl;
    std:: cout << scorpion->getType() << std::endl;

    zaz->attack(supermute);

    
    std::cout << *zaz;
    zaz->attack(scorpion);
    zaz->attack(supermute);
    zaz->attack(supermute);
    zaz->attack(supermute);
    zaz->attack(supermute);
    zaz->attack(supermute);
    std::cout << *zaz;

    zaz->recoverAP();
    std::cout << *zaz;
    zaz->attack(supermute);

    
    std::cout << *zaz;
    
    return 0;
}