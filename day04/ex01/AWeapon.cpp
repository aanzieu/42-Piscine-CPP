/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:29:02 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/06 10:43:23 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const &name, int apcost, int damage) : _name(name), _dmg(damage), _ap(apcost)
{
    return;
}

AWeapon::AWeapon(AWeapon const &src)
{
    *this = src;
    return;
}

AWeapon::~AWeapon(void)
{
    return;
}

AWeapon &AWeapon::operator=(AWeapon const &r)
{
    this->_name = r._name;
    this->_ap = r._ap;
    this->_dmg = r._dmg;
    return (*this);
}

std::string AWeapon::getName() const
{
    return (this->_name);
}

int AWeapon::getDamage() const
{
    return (this->_dmg);
}

int AWeapon::getAPCost() const
{
    return (this->_ap);
}
