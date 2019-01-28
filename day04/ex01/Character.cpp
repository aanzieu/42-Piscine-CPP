/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:29:05 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/06 12:07:42 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "Character.hpp"

Character::Character(std::string const &name) : _name(name), _weapon(NULL), _ap(40)
{
    return;
}

Character::Character(Character const &src)
{
    *this = src;
    return;
}

Character::~Character(void)
{
    return;
}

Character &Character::operator=(Character const &r)
{
    this->_name = r._name;
    this->_weapon = r._weapon;
    this->_ap = r._ap;
    return (*this);
}

std::string Character::getName(void) const
{
    return (this->_name);
}

int Character::getAP(void) const
{
    return (this->_ap);
}

AWeapon *Character::getWeapon(void) const
{
    return (this->_weapon);
}

void Character::recoverAP(void)
{
    this->_ap = this->_ap + 10;
    if (this->_ap > 40)
        this->_ap = 40;
}

void Character::equip(AWeapon *weapon)
{
    this->_weapon = weapon;
    return;
}

void Character::attack(Enemy *enemy)
{

    if (!enemy->getHP()){
        // std::cout << enemy->getType() << std::endl;
        return;
    }
    if (this->_weapon)
    {
        if (this->_ap != 0 && (this->_ap >= this->_weapon->getAPCost()))
        {
            std::cout << Character::cyan << this->_name << Character::reset << " attacks " << Character::red << enemy->getType() << Character::reset 
            << " with a " << Character::cyan <<this->_weapon->getName() << Character::reset << std::endl;
            this->_weapon->attack();
            enemy->takeDamage(this->_weapon->getDamage());
            this->_ap -= this->_weapon->getAPCost();
            if (enemy->getHP() <= 0)
                delete enemy;
        } else {
            std::cout << Character::magenta << this->_name << Character::red << "'s NEED RECOVERY WEAPON " << Character::reset  << std::endl;
        }
    }
    return;
}

std::ostream &operator<<(std::ostream &o, Character const &r)
{
    if (r.getWeapon())
        o << Character::magenta << r.getName() << Character::reset << " has " << Character::green << r.getAP() << Character::reset 
        << " AP and wields a " << Character::yellow << r.getWeapon()->getName() << Character::reset << std::endl;
    else
        o << Character::magenta << r.getName() << Character::reset << " has " << Character::green << r.getAP() << Character::reset << " AP and is unarmed" << std::endl;
    return (o);
}

const std::string Character::red = "\033[0;31m";
const std::string Character::green = "\033[1;32m";
const std::string Character::yellow = "\033[1;33m";
const std::string Character::cyan = "\033[0;36m";
const std::string Character::magenta = "\033[0;35m";
const std::string Character::reset = "\033[0m";