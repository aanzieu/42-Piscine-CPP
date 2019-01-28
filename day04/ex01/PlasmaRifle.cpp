/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:29:09 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/06 10:37:25 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void) : AWeapon("Plasma Rifle", 5, 21)
{
    return;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & src) : AWeapon(src)
{
    *this = src;
    return;
}

PlasmaRifle::~PlasmaRifle(void)
{
    return;
}

PlasmaRifle &PlasmaRifle::operator=(PlasmaRifle const & rhs)
{
    AWeapon::operator=(rhs);
    return (*this);
}

void PlasmaRifle::attack(void) const
{
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
    return;
}